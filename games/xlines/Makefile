# New ports collection makefile for:	xlines
# Version required:			1.0
# Date created:				11 February 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1998/07/11 00:39:24 steve Exp $
#

DISTNAME=	xlines
PKGNAME=	xlines-1.0
CATEGORIES=	games
MASTER_SITES=	ftp://risq.belcaf.minsk.by/pub/genie/

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	qt\\.1\\.:${PORTSDIR}/x11/qt
BUILD_DEPENDS=	moc:${PORTSDIR}/x11/qt

USE_X11=	yes
NO_WRKSUBDIR=	yes

pre-build:
	@ ${RM} ${WRKSRC}/lines.moc

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/xlines ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/xlines
	@ ${INSTALL_DATA} ${WRKSRC}/trolltech.gif ${PREFIX}/share/xlines
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/xlines
	@ ${INSTALL_DATA} ${WRKSRC}/readme.lines ${PREFIX}/share/doc/xlines
	@ ${INSTALL_DATA} ${WRKSRC}/readme.qt ${PREFIX}/share/doc/xlines
.endif

.include <bsd.port.mk>
