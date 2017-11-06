# MAINTAINER: ports@FreeBSD.org
# $FreeBSD$

BEGIN {
	gh_tuple_len = 0
	crates_len = 0
	package_name = "<unknown>"
}

/^"checksum .* .* \(registry\+.*\)" = ".*"/ {
	# $2: crate
	# $3: version
	# $4: url
	# $6: checksum
	crates[crates_len++] = sprintf("%s-%s", $2, $3)
}

/^name = ".*"/ {
	package_name = $3
	gsub("[^a-zA-Z_]", "", package_name)
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

/^source = "git\+(https|http|git):\/\/github.com\/.*#.*"/ {
	split_url(substr($3, 1, length($3) - 1))
	
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
	gh_tuple[gh_tuple_len++] = sprintf(\
		"%s:%s:%s:%s", account, project, tag, package_name)
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
	if (gh_tuple_len > 0 && ENVIRON["USE_GITHUB"] == "") {
		printf "USE_GITHUB=\tnodefault\n"
	}
	print_array("GH_TUPLE=", gh_tuple, gh_tuple_len)
	print_array("CARGO_CRATES=", crates, crates_len)
	if (gh_tuple_len > 0) {
		printf "CARGO_USE_GITHUB=\tyes\n"
	}
}
