# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	giflib
PORTVERSION=	5.2.1
PORTREVISION=	0
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	portmgr@FreeBSD.org
COMMENT=	Tools and library routines for working with GIF images

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	ghead:sysutils/coreutils

USES=		gmake
USE_LDCONFIG=	yes
CFLAGS+=	-DHAVE_REALLOCARRAY
MAKE_ARGS=	CC=${CC} LDFLAGS="${LDFLAGS}" MANDIR=${MANPREFIX}/man OFLAGS="${CFLAGS}" PREFIX="${PREFIX}"

OPTIONS_DEFINE=	DOCS
TEST_TARGET=	check

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! ( -name Makefile -o -name *\.1 -o -name *\.in -o -name *\.xml )"

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} --strip-unneeded ${STAGEDIR}${PREFIX}/lib/libgif.so.7.2.0

.include <bsd.port.mk>
