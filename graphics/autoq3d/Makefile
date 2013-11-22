# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	autoq3d
PORTVERSION=	1.40
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/AutoQ3D%20${PORTVERSION}
DISTNAME=	AutoQ3DCommunity${PORTVERSION:C/\./-/}qt4source

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Qt 4 quick 3D model editor

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		dos2unix qmake
USE_GL=		glu
USE_ZIP=	yes
USE_QT4=	corelib gui opengl moc_build

PORTDOCS=	3DQformat.txt ChangeLog.txt

DESKTOP_ENTRIES="AutoQ3D" \
		"${COMMENT}" \
		"AutoQ3D" \
		"AutoQ3D" \
		"Graphics;3DGraphics;Qt;" \
		true

.include <bsd.port.options.mk>
post-patch:
.for file in src/main.cpp src/fgui/cadform.cpp src/dialogs/prgsettings.cpp
	@${REINPLACE_CMD} -e \
		's|/usr/share/AutoQ3D-Community|${DATADIR}|g' ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/AutoQ3D ${STAGEDIR}${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "images *.htm *.qm" ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/AutoQ3D.png ${STAGEDIR}${PREFIX}/share/pixmaps
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
