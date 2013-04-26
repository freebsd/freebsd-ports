# Created by: Mitsuru Y <mitsuruy@reallyenglish.com>
# $FreeBSD$

MAINTAINER=	mitsuruy@reallyenglish.com
COMMENT=	An object-oriented interpreted scripting language

PLIST=		${.CURDIR}/pkg-plist

MASTERDIR=	${.CURDIR}/../rbenv-ruby

RUBY_VERSION=	1.8.7
RUBY_PATCHLEVEL=	357

PLIST_SUB+=	RUBY_PATCHLEVEL=${RUBY_PATCHLEVEL}

RBCONFIG=	rbenv_root/versions/${RUBY_VERSION}-p${RUBY_PATCHLEVEL}/lib/ruby/1.8/x86_64-freebsd${OSREL}/rbconfig.rb

.include "${MASTERDIR}/Makefile"
