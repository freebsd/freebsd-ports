# New ports collection makefile for:	scare
# Date created:				6 February 2005
# Whom:					Peter Pentchev <roam@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scare
PORTVERSION=	1.3.7
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.ifarchive.org/if-archive/programming/adrift/ \
		http://www.geocities.com/legion_if/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	ADRIFT-compatible interactive games interpreter

OPTIONS=	XGLK "Use the xglk graphics library" off

USE_ZIP=	yes

.include <bsd.port.pre.mk>

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

BINFILES=	scare

.if defined(WITH_XGLK)
PKGNAMESUFFIX=	-glk

BUILD_DEPENDS+=	${LOCALBASE}/lib/libxglk.a:${PORTSDIR}/games/xglk
RUN_DEPENDS+=	${LOCALBASE}/lib/libxglk.a:${PORTSDIR}/games/xglk

ALL_TARGET=	all glkscare

EXTRA_PATCHES=	${FILESDIR}/xglk.patch

BINFILES+=	glkscare
.else
EXTRA_PATCHES=	${FILESDIR}/no-xglk.patch
.endif

PLIST_FILES=	${BINFILES:S,^,bin/,}

do-install:
		${INSTALL_PROGRAM} ${BINFILES:S,^,${WRKSRC}/source/,} ${PREFIX}/bin/

test:	build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check

.include <bsd.port.post.mk>
