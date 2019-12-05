# MAINTAINER: rust@FreeBSD.org
# $FreeBSD$

BEGIN {
	gh_tuple_len = 0
	gl_tuple_len = 0
	crates_len = 0
	package_name = "<unknown>"
	crate_name = "<unknown>"
	crate_version = "<unknown>"
	crate_source = "<unknown>"

	gitlab_sites["https://gitlab.com"] = 1
	gitlab_sites["https://gitlab.freedesktop.org"] = 1
	gitlab_sites["https://gitlab.gnome.org"] = 1
	gitlab_sites["https://gitlab.redox-os.org"] = 1
}

/^name = ".*"/ {
	crate_name = $3
	gsub(/"/, "", crate_name)

	package_name = $3
	gsub("[^a-zA-Z_]", "", package_name)
}

/^version = ".*"/ {
	crate_version = $3
	gsub(/"/, "", crate_version)
}

/^source = ".*"/ {
	crate_source = $3
	gsub(/"/, "", crate_source)
}

/^\[\[package\]\]$/ {
	add_crate()
}

function add_crate() {
	if (crate_source == "registry+https://github.com/rust-lang/crates.io-index") {
		crates[crates_len++] = sprintf("%s-%s", crate_name, crate_version)
	}
	crate_name = "<unknown>"
	crate_version = "<unknown>"
	crate_source = "<unknown>"
}

function split_url(s) {
	# scheme:[//[user[:password]@]host[:port]][/path][?query][#fragment]
	split(s, url_scheme, "://")
	url["scheme"] = url_scheme[1]

	split(url_scheme[2], url_fragment, "#")
	url["fragment"] = url_fragment[2]

	split(url_fragment[1], url_query, "?")
	url["query"] = url_query[2]

	split(url_query[1], url_authority, "/")
	url["path"] = substr(url_query[1], length(url_authority[1]) + 1)

	split(url_authority[1], url_auth, "@")

	if (length(url_auth) == 2) {
		split(url_auth[1], url_user, ":")
		url["user"] = url_user[1]
		url["password"] = url_user[2]
		split(url_auth[2], url_host, ":")
	} else {
		url["user"] = ""
		url["password"] = ""
		split(url_auth[1], url_host, ":")
	}
	url["host"] = url_host[1]
	url["port"] = url_host[2]
}

!gh_tuple_seen[$0] && /^source = "git\+(https|http|git):\/\/.*\/.*#.*"/ {
	gh_tuple_seen[$0] = 1
	split_url(substr($3, 1 + length("\"git+"), length($3) - 1 - length("\"git+")))

	split(url["path"], path, "/")
	account = path[2]
	project = path[3]
	gsub("\.git$", "", project)

	if (match(url["query"], "^tag=")) {
		split(url["query"], tag_, "=")
		tag = tag_[2]
	} else {
		tag = url["fragment"]
	}

	added = 0
	if (url["host"] == "github.com") {
		added = 1
		gh_tuple[gh_tuple_len++] = sprintf(\
			"%s:%s:%s:%s", account, project, tag, package_name)
	} else {
		repo_site = sprintf("%s://%s", url["scheme"], url["host"])
		for (site in gitlab_sites) {
			if (repo_site != site) {
				continue
			}
			if (ENVIRON["GL_SITE"] == site) {
				gl_tuple[gl_tuple_len++] = sprintf(\
					"%s:%s:%s:%s", account, project, tag, package_name)
			} else {
				gl_tuple[gl_tuple_len++] = sprintf(\
					"%s:%s:%s:%s:%s", site, account, project, tag, package_name)
			}
			added = 1
			break
		}
	}

	if (!added) {
		printf "Warning: Ignoring git source on line %d: %s\n", NR, $3 > "/dev/stderr"
	}
}

function print_array(start, arr, arrlen) {
	end = " \\\n"
	for (i = 0; i < arrlen; i++) {
		if (i == arrlen - 1) {
			end = "\n"
		}
		printf "%s\t%s%s", start, arr[i], end
		start = "\t"
	}
}

END {
	add_crate()

	if (gh_tuple_len > 0 && ENVIRON["USE_GITHUB"] == "") {
		printf "USE_GITHUB=\tnodefault\n"
	}
	print_array("GH_TUPLE=", gh_tuple, gh_tuple_len)
	if (gl_tuple_len > 0 && ENVIRON["USE_GITLAB"] == "") {
		printf "USE_GITLAB=\tnodefault\n"
	}
	print_array("GL_TUPLE=", gl_tuple, gl_tuple_len)
	print_array("CARGO_CRATES=", crates, crates_len)
	if (gh_tuple_len > 0) {
		printf "CARGO_USE_GITHUB=\tyes\n"
	}
	if (gl_tuple_len > 0) {
		printf "CARGO_USE_GITLAB=\tyes\n"
	}
}
