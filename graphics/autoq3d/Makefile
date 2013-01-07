# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	autoq3d
PORTVERSION=	1.40
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/AutoQ3D%20${PORTVERSION}
DISTNAME=	AutoQ3DCommunity${PORTVERSION:C/\./-/}qt4source

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Qt4 quick 3D model editor

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_DOS2UNIX=	yes
USE_GL=		glu
USE_ZIP=	yes
USE_QT4=	corelib gui opengl \
		moc_build qmake_build
MAKE_JOBS_SAFE=	yes

PORTDOCS=	3DQformat.txt ChangeLog.txt

DESKTOP_ENTRIES="AutoQ3D" \
		"${COMMENT}" \
		"AutoQ3D" \
		"AutoQ3D" \
		"Graphics;3DGraphics;Qt;" \
		false

.include <bsd.port.options.mk>
post-patch:
.for file in src/main.cpp src/fgui/cadform.cpp src/dialogs/prgsettings.cpp
	@${REINPLACE_CMD} -e \
		's|/usr/share/AutoQ3D-Community|${DATADIR}|g' ${WRKSRC}/${file}
.endfor

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/AutoQ3D ${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "images *.htm *.qm" ${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/AutoQ3D.png ${PREFIX}/share/pixmaps
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
