# New ports collection makefile for:	ja-S-lang library
# Date created:		3 September 1999
# Whom:			IWASHITA Yoji <shuna@pop16.odn.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	libslang
PORTVERSION=	${VERSION}.j${JP_VERSION}
CATEGORIES=	japanese devel
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slang/v1.4/
DISTNAME=	slang-${VERSION}

PATCH_SITES=	http://www.asmnet.ne.jp/~matubara/src/
PATCHFILES=	slang-${VERSION}jp${JP_VERSION}.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	mega@minz.org

VERSION=	1.4.5
JP_VERSION=	0

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/slang
ALL_TARGET=	all elf
INSTALL_TARGET=	install-elf
INSTALLS_SHLIB=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/slang-j.doc ${PREFIX}/share/doc/slang

.include <bsd.port.mk>
