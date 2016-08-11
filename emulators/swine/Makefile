# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	swine
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	emulators deskutils python

MAINTAINER=	koalative@gmail.com
COMMENT=	Qt4 graphical Wine frontend

LICENSE=	GPLv2

BUILD_DEPENDS=	pyrcc4:textproc/py-qt4-xml
RUN_DEPENDS=	xterm:x11/xterm \
		cabextract:archivers/cabextract \
		icotool:graphics/icoutils \
		${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:x11-toolkits/py-qt4-gui

DATADIRLIB=	${PREFIX}/lib/${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	dswd
GH_PROJECT=	Swine

USES=		gmake python
NO_BUILD=	yes
USE_QT4=	linguist_build
ONLY_FOR_ARCHS=	i386 amd64

PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
RUN_DEPENDS+=	wine:emulators/wine-devel
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' ${WRKSRC}/version.sh
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}| ; \
			s|swine32.png|*|' \
	${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/share/swine/images/swine32.png|swine|' \
		-e 's|^Categories=.*|Categories=Wine;System;Emulator;Utility;Game;|' \
		${WRKSRC}/resources/swine.desktop

post-install:
	${LN} -sf ${DATADIR}/images/swine32.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
