#!/bin/sh
# Requires: pkg install portfmt yq
# Run in lang/rust
set -eu

fetch -qo /tmp/channel-rust-stable.toml https://dev-static.rust-lang.org/dist/channel-rust-stable.toml
version=$(</tmp/channel-rust-stable.toml tomlq -r '.pkg.rustc.version | split(" ")[0]')
new_commit=$(</tmp/channel-rust-stable.toml tomlq -r '.pkg.rustc.git_commit_hash')
rm /tmp/channel-rust-stable.toml

fetch -qo /tmp/stage0 https://raw.githubusercontent.com/rust-lang/rust/${new_commit}/src/stage0
BOOTSTRAPS_DATE=$(awk -F "=" /^compiler_date/'{print $2}' /tmp/stage0)
RUST_BOOTSTRAP_VERSION=$(awk -F "=" /^compiler_version/'{print $2}' /tmp/stage0)
echo "BOOTSTRAPS_DATE=${BOOTSTRAPS_DATE}" | portedit merge -i .
echo "RUST_BOOTSTRAP_VERSION=${RUST_BOOTSTRAP_VERSION}" | portedit merge -i .

cat <<EOF | sed -i '' -E -f - ../../Mk/Uses/cargo.mk ../../Mk/bsd.gecko.mk
1,/\\$\\{RUST_DEFAULT\\}>=/ {
	s,(\\$\\{RUST_DEFAULT\\}>=).*(:lang/\\$\\{RUST_DEFAULT\\}),\\1${version}\\2,
}
EOF

portedit set-version -i "${version}" .
portedit set-version -i "${version}" ../rust-bootstrap

make makesum
make -C ../rust-bootstrap makesum

echo "lang/rust: Update to ${version}

https://blog.rust-lang.org/FIXME/Rust-${version}.html

PR:		FIXME
Exp-run by:	antoine
Differential Revision:	FIXME" >rust.msg
