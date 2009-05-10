# New ports collection makefile for:	autoq3d
# Date created:		28 Jul 2007
# Whom:                	Yinghong.Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	autoq3d
DISTVERSION=	1.36
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	AutoQ3DGPL${PORTVERSION:C/\./-/}qt4source

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A complete QT quick 3d model editor program

USE_ZIP=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build corelib moc_build gui opengl

PORTDOCS=	3DQformat.txt ChangeLog.txt Install.txt license.txt

.if !defined(WITHOUT_NLS)
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

DESKTOP_ENTRIES=	"AutoQ3D" \
			"A complete QT quick 3d model editor program" \
			"AutoQ3D" \
			"AutoQ3D" \
			"Qt;KDE;Graphics;" \
			"false"

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/AutoQ3D-GPL|${DATADIR}|g' \
		${WRKSRC}/src/main.cpp \
		${WRKSRC}/src/fgui/cadform.cpp \
		${WRKSRC}/src/dialogs/prgsettings.cpp

pre-build:
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${QMAKE} -spec ${QMAKESPEC}

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/AutoQ3D ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/pixmaps
	@${INSTALL_DATA} ${WRKSRC}/AutoQ3D.png ${PREFIX}/share/pixmaps
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/qref*.htm ${DATADIR}
	@${MKDIR} ${DATADIR}/images
	@${INSTALL_DATA} ${WRKSRC}/images/*.png ${DATADIR}/images
.if !defined(WITHOUT_NLS)
	@${INSTALL_DATA} ${WRKSRC}/*.qm ${DATADIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/docs/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
