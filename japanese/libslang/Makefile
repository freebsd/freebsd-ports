# New ports collection makefile for:	ja-S-lang library
# Date created:		3 September 1999
# Whom:			IWASHITA Yoji <shuna@pop16.odn.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	libslang
PORTVERSION=	${VERSION}.j${JP_VERSION}
CATEGORIES=	japanese devel
MASTER_SITES=	http://www.actweb.ne.jp/k-yosino/ \
		http://home.sprintmail.com/~kikutani/slang/
DISTNAME=	slang-${VERSION}jp${JP_VERSION}

MAINTAINER=	mega@minz.org

VERSION=	1.4.1
JP_VERSION=	0

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/slang
ALL_TARGET=	all elf
INSTALL_TARGET=	install-elf
INSTALLS_SHLIB=	yes

post-install:
	${CP} ${WRKSRC}/slang-j.doc ${PREFIX}/share/doc/slang

.include <bsd.port.mk>
