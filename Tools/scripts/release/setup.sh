#!/bin/sh
# $FreeBSD$

dir="/var/portbuild/4/bak"

tar xzvf $dir/ports.tar.gz
cd ports
rm -f distfiles packages
mkdir distfiles packages
(echo "copying packages ..." && cd packages && cp -R $dir/packages/ .)
#(echo "copying distfiles ..." && cd distfiles && cp -R $dir/distfiles/ .)
