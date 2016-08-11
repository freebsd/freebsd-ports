# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	seam-carving-gui
PORTVERSION=	1.11
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	SeamCarvingGui-Src-${PORTVERSION}

MAINTAINER=	buganini@gmail.com
COMMENT=	The Seam Carving GUI is a GUI front end to CAIR

USES=		dos2unix gmake qmake
DOS2UNIX_GLOB=	*.cpp
USE_QT4=	gui imageformats_run moc_build uic_build

WRKSRC=		${WRKDIR}/Src\ Seam\ Carving\ GUI\ ${PORTVERSION}

PLIST_FILES=	bin/SeamCarvingGui

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/SeamCarvingGui ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
