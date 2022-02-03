#!/bin/sh
# Requires: pkg install portfmt yq
# Run in lang/rust-nightly
set -eu

prev_date=$(portedit get '^NIGHTLY_DATE$' .)
prev_commit=$(fetch -qo - https://static.rust-lang.org/dist/${prev_date}/channel-rust-nightly.toml | tomlq -r '.pkg.rustc.git_commit_hash')
fetch -qo /tmp/channel-rust-nightly.toml https://static.rust-lang.org/dist/channel-rust-nightly.toml
</tmp/channel-rust-nightly.toml tomlq -r '
	"PORTVERSION=\(.pkg.rustc.version | split("-nightly")[0]).${NIGHTLY_DATE:C,-,,g}",
	"PORTREVISION=0",
	"NIGHTLY_DATE=\(.pkg.rustc.version | split(" ")[2][:-1])"
' | portedit merge -i .
new_commit=$(</tmp/channel-rust-nightly.toml tomlq -r '.pkg.rustc.git_commit_hash')
rm /tmp/channel-rust-nightly.toml

fetch -qo - https://raw.githubusercontent.com/rust-lang/rust/${new_commit}/src/stage0.json | jq -r '
	"BOOTSTRAPS_DATE=\(.compiler.date)",
	"RUST_BOOTSTRAP_VERSION=\(.compiler.version)"
' | portedit merge -i .

make makesum
echo "lang/rust-nightly: Update to $(make -V PORTVERSION)

https://github.com/rust-lang/rust/compare/${prev_commit}...${new_commit}" >rust-nightly.msg
