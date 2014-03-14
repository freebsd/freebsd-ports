# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	autoq3d
PORTVERSION=	1.40
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/AutoQ3D%20${PORTVERSION}
DISTNAME=	AutoQ3DCommunity${PORTVERSION:C/\./-/}qt4source

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Qt 4 quick 3D model editor

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		dos2unix qmake zip
DOS2UNIX_FILES=	*.pro src/cmds/*.cpp src/fgui/*.cpp docs/*.txt
DOS2UNIX_REGEX=	.*.[^p][^n][^g]$
USE_GL=		glu
USE_QT4=	corelib gui opengl moc_build

PORTDOCS=	3DQformat.txt ChangeLog.txt

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="AutoQ3D" "" "${PORTNAME}" \
		"${PORTNAME}" "Graphics;3DGraphics;Qt;" ""

post-patch:
.for file in src/main.cpp src/fgui/cadform.cpp src/dialogs/prgsettings.cpp
	@${REINPLACE_CMD} \
		-e 's|/usr/share/AutoQ3D-Community|${DATADIR}|g' \
		${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/AutoQ3D ${STAGEDIR}${PREFIX}/bin/
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "images *.htm *.qm" \
		${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/AutoQ3D.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
