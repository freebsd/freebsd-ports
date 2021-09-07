# MAINTAINER: rust@FreeBSD.org

BEGIN {
	crates_len = 0
	crate_name = "<unknown>"
	crate_version = "<unknown>"
	crate_source = "<unknown>"
}

/^name = ".*"/ {
	crate_name = $3
	gsub(/"/, "", crate_name)
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
	if (crate_source ~ /^git\+/) {
		gsub(/#/, "\\#", crate_source)
		if (git_crates[crate_source]) {
			git_crates[crate_source] = git_crates[crate_source] "," crate_name
		} else {
			git_crates[crate_source] = crate_name
		}
	} else if (crate_source == "registry+https://github.com/rust-lang/crates.io-index") {
		crates[crates_len++] = sprintf("%s-%s", crate_name, crate_version)
	}
	crate_name = "<unknown>"
	crate_version = "<unknown>"
	crate_source = "<unknown>"
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
	for (crate_source in git_crates) {
		crates[crates_len++] = git_crates[crate_source] "@" crate_source
	}
	print_array("CARGO_CRATES=", crates, crates_len)
}
