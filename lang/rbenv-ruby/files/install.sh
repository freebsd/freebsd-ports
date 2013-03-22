#!/usr/bin/env bash
export PATH="%%PREFIX%%/rbenv/bin:$PATH"
export RBENV_ROOT="%%PREFIX%%/rbenv_root"
export CONFIGURE_OPTS="--with-iconv-dir=%%PREFIX%%"
export CC=gcc
eval "$(rbenv init -)"
rbenv install $1
