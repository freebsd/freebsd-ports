# Created by: Rusmir Dusko <nemysis@FreeBSD.org>
# $FreeBSD$

PORTNAME=	swine
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	emulators deskutils python

MAINTAINER=	koalative@gmail.com
COMMENT=	Qt4 graphical Wine frontend

LICENSE=	GPLv2

BUILD_DEPENDS=	pyrcc4:${PORTSDIR}/textproc/py-qt4-xml
RUN_DEPENDS=	xterm:${PORTSDIR}/x11/xterm \
		cabextract:${PORTSDIR}/archivers/cabextract \
		icotool:${PORTSDIR}/graphics/icoutils \
		${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui

DATADIRLIB=	${PREFIX}/lib/${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	dswd
GH_PROJECT=	Swine
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	1770c40

USES=		gmake
USE_PYTHON=	yes
NO_BUILD=	yes
USE_QT4=	linguist_build
ONLY_FOR_ARCHS=	i386 amd64

PORTDOCS=	README
OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
RUN_DEPENDS+=	wine:${PORTSDIR}/emulators/wine-devel
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
