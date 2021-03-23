#!/bin/sh
# Requires: pkg install portfmt
# Run in lang/rust-nightly
set -eu

get_commit() {
	awk '
$1 == "[pkg.rustc]" { pkg_rustc = 1 }
pkg_rustc && $1 == "git_commit_hash" {
	print substr($3, 2, 10)
	exit
}'
}

prev_date=$(portedit get '^NIGHTLY_DATE$' .)
prev_commit=$(fetch -qo - https://static.rust-lang.org/dist/${prev_date}/channel-rust-nightly.toml | get_commit)
fetch -qo /tmp/channel-rust-nightly.toml https://static.rust-lang.org/dist/channel-rust-nightly.toml
</tmp/channel-rust-nightly.toml awk '
$1 == "[pkg.rustc]" { pkg_rustc = 1 }
date == "" && $1 == "date" { date = substr($3, 2, length($3) - 2) }
date && pkg_rustc && $1 == "version" {
	version = substr($3, 2, length($3) - length("-nightly") - 1)
	printf("PORTVERSION=%s.${NIGHTLY_DATE:C,-,,g}\nPORTREVISION=0\nNIGHTLY_DATE=%s\n", version, date)
	exit
}' | portedit merge -i .
new_commit=$(</tmp/channel-rust-nightly.toml get_commit)
rm /tmp/channel-rust-nightly.toml

fetch -qo - https://raw.githubusercontent.com/rust-lang/rust/${new_commit}/src/stage0.txt | awk '
$1 == "date:" { date = $2 }
$1 == "rustc:" { rustc = $2 }
END { printf("BOOTSTRAPS_DATE=%s\nRUST_BOOTSTRAP_VERSION=%s\n", date, rustc) }' | portedit merge -i .

make makesum
echo "lang/rust-nightly: Update to $(make -V PORTVERSION)

Changes:	https://github.com/rust-lang/rust/compare/${prev_commit}...${new_commit}" >rust-nightly.msg
