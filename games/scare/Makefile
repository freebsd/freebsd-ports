# New ports collection makefile for:	scare
# Date created:				6 February 2005
# Whom:					Peter Pentchev <roam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scare
PORTVERSION=	1.3.3
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.ifarchive.org/if-archive/programming/adrift/ \
		http://www.geocities.com/legion_if/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	ADRIFT-compatible interactive games interpreter

USE_ZIP=	yes

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

BINFILES=	scare

.if defined(WITH_XGLK)
PKGNAMESUFFIX=	-glk

BUILD_DEPENDS+=	${X11BASE}/lib/libxglk.a:${PORTSDIR}/games/xglk
RUN_DEPENDS+=	${X11BASE}/lib/libxglk.a:${PORTSDIR}/games/xglk

ALL_TARGET=	all glkscare

EXTRA_PATCHES=	${FILESDIR}/xglk.patch

BINFILES+=	glkscare
.else
EXTRA_PATCHES=	${FILESDIR}/no-xglk.patch
.endif

PLIST_FILES=	${BINFILES:S,^,bin/,}

do-install:
		${INSTALL_PROGRAM} ${BINFILES:S,^,${WRKSRC}/,} ${PREFIX}/bin/

.include <bsd.port.mk>
