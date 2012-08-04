# New ports collection makefile for:	KnightCap
# Date created:				10 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	knightcap
PORTVERSION=	3.6
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.samba.org/pub/KnightCap/
DISTNAME=	KnightCap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chess program with 3D interface for X Window System

WRKSRC=		${WRKDIR}/Export

USE_XORG=	xmu xt xext x11 xi
USE_GL=		glut
ALL_TARGET=	KnightCap

DOCSDIR=	${PREFIX}/share/doc/KnightCap
PORTDOCS=	README
PLIST_FILES=	bin/KnightCap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/KnightCap ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
