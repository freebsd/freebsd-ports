# Created by: Mitsuru Y <mitsuruy@reallyenglish.com>
# $FreeBSD$

MAINTAINER=	mitsuruy@reallyenglish.com
COMMENT=	An object-oriented interpreted scripting language

PLIST=		${.CURDIR}/pkg-plist

LIB_DEPENDS=	yaml-0.2:${PORTSDIR}/textproc/libyaml

MASTERDIR=	${.CURDIR}/../rbenv-ruby

RUBY_VERSION=	1.9.3
RUBY_PATCHLEVEL=	392

PLIST_SUB+=	RUBY_PATCHLEVEL=${RUBY_PATCHLEVEL}

RBCONFIG=	rbenv_root/versions/1.9.3-p${RUBY_PATCHLEVEL}/lib/ruby/1.9.1/x86_64-freebsd${OSREL}/rbconfig.rb

.include "${MASTERDIR}/Makefile"
