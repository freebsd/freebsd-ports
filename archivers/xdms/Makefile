# New ports collection makefile for:	xdms
# Date created:			Apr 13, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	xdms
PORTVERSION=	1.3.1
CATEGORIES=	archivers
MASTER_SITES=	http://www.modeemi.fi/~shd/xdms/

MAINTAINER=	markp@FreeBSD.org
COMMENT=	An Amiga DMS archiver unpacker

USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
ALL_TARGET=	xdms

post-patch:
	${REINPLACE_CMD} "s@-O3 -Wall@-Wall@g" ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xdms ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/xdms
	${INSTALL_DATA} ${WRKSRC}/xdms.txt ${PREFIX}/share/doc/xdms
.endif

.include <bsd.port.mk>
