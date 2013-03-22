# Created by: Mitsuru Y <mitsuruy@reallyenglish.com>
# $FreeBSD$

MAINTAINER=	mitsuruy@reallyenglish.com
COMMENT=	An object-oriented interpreted scripting language

PLIST=		${.CURDIR}/pkg-plist

LIB_DEPENDS=	yaml-0.2:${PORTSDIR}/textproc/libyaml

MASTERDIR=	${.CURDIR}/../rbenv-ruby

RUBY_VERSION=	1.9.3
RUBY_PATCHLEVEL=	385

RBCONFIG=	rbenv_root/versions/1.9.3-p385/lib/ruby/1.9.1/x86_64-freebsd9.1/rbconfig.rb

.include "${MASTERDIR}/Makefile"
