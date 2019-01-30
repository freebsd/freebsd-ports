# Case-insensitive bubble sort
function sort_array(arr, arrlen,	i, j, temp) {
	for (i = 1; i < arrlen; i++) {
		for (j = i + 1; j < arrlen; j++) {
			if (tolower(arr[i]) > tolower(arr[j])) {
				temp = arr[j]
				arr[j] = arr[i]
				arr[i] = temp
			}
		}
	}
}

function print_array(start, arr, arrlen,	end, i) {
	end = " \\\n"
	for (i = 1; i < arrlen; i++) {
		if (i == arrlen - 1) {
			end = "\n"
		}
		printf "%s\t%s%s", start, arr[i], end
		start = "\t"
	}
}

function distgroup(name,	retval) {
	gsub(/[-\.]/, "_", name)
	if (_distgroup[name] == 0) {
		_distgroup[name] = 1
		return name
	}

	retval = sprintf("%s%i", name, _distgroup[name]++)
	return retval
}

BEGIN {
	module = "<<<unknown>>>"

	# Map some modules to GitHub manually
	# XXX: This could be done automatically via looking it up with curl
	# https://google.golang.org/grpc?go-get=1
	# or via go get -v honnef.co/go/tools
	github_map["google.golang.org/api"] = "google/google-api-go-client"
	github_map["google.golang.org/grpc"] = "grpc/grpc-go"
	github_map["google.golang.org/genproto"] = "google/go-genproto"
	github_map["go4.org"] = "go4org/go4"
	github_map["honnef.co/go/tools"] = "dominikh/go-tools"
}

$1 ~ /module/ {
	module = $2
}

/^require \($/, /^\)$/ {
	if ($1 != "require" && $1 != ")") {
		require()
	}
} function require(	dep, version) {
	dep = $1
	version = $2
	_require[dep] = version
}

/^replace / {
	replace()
} function replace(	old_dep, new_dep, version) {
	old_dep = $2
	new_dep = $4
	version = $5
	delete _require[old_dep]
	_require[new_dep] = version
	_replace[new_dep] = old_dep
}

function to_gh_tuple(tuples,	tmp, path, account, project, tag, tokens) {
	tuples_len = 1
	for (path in _require) {
		split(path, tokens, "/")
		account = "<<<unknown>>>"
		project = "<<<unknown>>>"
		tag = _require[path]
		if (path ~ "^golang.org/x/") {
			account = "golang"
			project = tokens[3]
		} else if (path ~ "^(github|sourcegraph).com/") {
			account = tokens[2]
			project = tokens[3]
		} else if (path ~ "^gopkg.in/") {
			if (length(tokens) >= 3) {
				gsub(/\.v[0-9]+$/, "", tokens[3])
				account = tokens[2]
				project = tokens[3]
			} else if (length(tokens) >= 2) {
				gsub(/\.v[0-9]+$/, "", tokens[2])
				account = sprintf("go-%s", tokens[2])
				project = tokens[2]
			}
		} else if (path ~ "^git.apache.org/") {
			account = "apache"
			project = tokens[2]
		} else {
			if (split(github_map[path], tmp, "/") == 2) {
				account = tmp[1]
				project = tmp[2]
			}
		}
		gsub(/\+.*$/, "", tag)
		gsub(/^v[0-9\.]+-..............-/, "", tag)
		gsub(/\.git$/, "", project)
		if (_replace[path] != "") {
			path = _replace[path]
		}
		tuples[tuples_len++] = sprintf("%s:%s:%s:%s/vendor/%s", account, project, tag, distgroup(project), path)
	}
	return tuples_len
}

function print_gh_tuple(	tuples_len, tuples) {
	tuples_len = to_gh_tuple(tuples)
	sort_array(tuples, tuples_len)
	print_array("GH_TUPLE=", tuples, tuples_len)
}

END {
	print_gh_tuple()
}
