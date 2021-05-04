#!/bin/sh
# Requires: pkg install portfmt
# Run in lang/rust
set -eu

get_commit() {
	awk '
$1 == "[pkg.rustc]" { pkg_rustc = 1 }
pkg_rustc && $1 == "git_commit_hash" {
	print substr($3, 2, 10)
	exit
}'
}

fetch -qo /tmp/channel-rust-stable.toml https://dev-static.rust-lang.org/dist/channel-rust-stable.toml
version=$(</tmp/channel-rust-stable.toml awk '
$1 == "[pkg.rustc]" { pkg_rustc = 1 }
pkg_rustc && $1 == "version" {
	print substr($3, 2, length($3) - 1)
	exit
}')
new_commit=$(</tmp/channel-rust-stable.toml get_commit)
rm /tmp/channel-rust-stable.toml

fetch -qo - https://raw.githubusercontent.com/rust-lang/rust/${new_commit}/src/stage0.txt | awk '
$1 == "date:" { date = $2 }
$1 == "rustc:" { rustc = $2 }
END { printf("BOOTSTRAPS_DATE=%s\nRUST_BOOTSTRAP_VERSION=%s\n", date, rustc) }' | portedit merge -i .

sed -i '' -E -e "s,(\\$\\{RUST_DEFAULT\\}>=).*(:lang/\\$\\{RUST_DEFAULT\\}),\\1${version}\\2," \
	../../Mk/Uses/cargo.mk ../../Mk/bsd.gecko.mk

portedit set-version -i "${version}" .
make makesum
portedit set-version -i "${version}" ../rust-bootstrap
make -C ../rust-bootstrap makesum

echo "lang/rust: Update to ${version}

Changes:	https://blog.rust-lang.org/FIXME/Rust-${version}.html
PR:		FIXME
Exp-run by:	antoine
Differential Revision:	FIXME" >rust.msg
