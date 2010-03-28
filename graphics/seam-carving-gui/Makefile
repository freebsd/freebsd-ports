# New ports collection makefile for:	seam-carving-gui
# Date created:				18 Oct 2008
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	seam-carving-gui
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	SeamCarvingGui-Src-${PORTVERSION}

MAINTAINER=	buganini@gmail.com
COMMENT=	The Seam Carving GUI is a GUI front end to CAIR

HAS_CONFIGURE=	yes

USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui imageformats_run moc_build qmake_build uic_build

WRKSRC=		${WRKDIR}/Src\ Seam\ Carving\ GUI\ ${PORTVERSION}

PLIST_FILES=	bin/SeamCarvingGui

do-configure:
	cd ${WRKSRC} && 	\
	${SETENV} QMAKESPEC="${QMAKESPEC}" ${QMAKE} seam-carving-gui.pro

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/SeamCarvingGui ${PREFIX}/bin

.include <bsd.port.mk>
