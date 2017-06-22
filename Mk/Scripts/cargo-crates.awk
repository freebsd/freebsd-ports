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

/^source = "git\+(https|http|git):\/\/github.com\/.*#.*"/ {
	split($3, url, "#")

	gsub("^\"git\+", "", url[1])
	split(url[1], repourl, "/")
	account = repourl[4]
	project = repourl[5]
	gsub("\.git$", "", project)

	tag = url[2]
	gsub("\"$", "", tag)

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
