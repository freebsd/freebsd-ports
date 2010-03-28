# New ports collection makefile for:	autoq3d
# Date created:		28 Jul 2007
# Whom:                	Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	autoq3d
DISTVERSION=	1.39
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/AutoQ3D%20${PORTVERSION}
DISTNAME=	AutoQ3DCommunity${PORTVERSION:C/\./-/}qt4source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A complete QT quick 3d model editor program

USE_ZIP=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui opengl \
		moc_build qmake_build

DESKTOP_ENTRIES=	"AutoQ3D" \
			"A complete QT quick 3d model editor program" \
			"AutoQ3D" \
			"AutoQ3D" \
			"Qt;KDE;Graphics;" \
			"false"

post-patch:
.for file in src/main.cpp src/fgui/cadform.cpp src/dialogs/prgsettings.cpp
	@${REINPLACE_CMD} -e \
		's|/usr/share/AutoQ3D-Community|${DATADIR}|g' ${WRKSRC}/${file}
.endfor

do-configure:
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${QMAKE} -spec ${QMAKESPEC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/AutoQ3D ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.htm ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.qm ${DATADIR}
	@${MKDIR} ${DATADIR}/images
	${INSTALL_DATA} ${WRKSRC}/images/*.png ${DATADIR}/images
	@${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/AutoQ3D.png ${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
