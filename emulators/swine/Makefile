# Created by:   nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	swine
PORTVERSION=	1.0.2
CATEGORIES=	emulators deskutils python
MASTER_SITES=	GH

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Qt4 graphical Wine frontend

LICENSE=	GPLv2

BUILD_DEPENDS=	pyrcc4:${PORTSDIR}/textproc/py-qt4-xml
RUN_DEPENDS=	wine:${PORTSDIR}/emulators/wine-devel \
		xterm:${PORTSDIR}/x11/xterm \
		cabextract:${PORTSDIR}/archivers/cabextract \
		icotool:${PORTSDIR}/graphics/icoutils \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=${PYQT4_VERSION}:${PORTSDIR}/x11-toolkits/py-qt4-gui

DATADIRLIB=	${PREFIX}/lib/${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	dswd
GH_PROJECT=	Swine
GH_TAGNAME=	master
GH_COMMIT=	d14b9f0

USE_PYTHON=	yes
USE_GMAKE=	yes
USE_QT4=	linguist_build

PORTDOCS=	README

.include "../../devel/py-sip/files/bsd.pyqt.mk"
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|' ${WRKSRC}/version.sh

pre-build:
.if !exists(${LOCALBASE}/bin/wine) && ${ARCH} != "i386"
	@${ECHO_MSG}
	@${ECHO_MSG} "Depends on Wine Port which is only available for i386"
	@${ECHO_MSG}
	@${ECHO_MSG} "	http://wiki.freebsd.org/Wine"
	@${ECHO_MSG}
	@${ECHO_MSG} "FreeBSD/amd64 works with Wine 32bit binary from"
	@${ECHO_MSG}
	@${ECHO_MSG} "	http://www.mediafire.com/wine_fbsd64"
	@${ECHO_MSG}
	exit 1
.endif

do-build:
	@(cd ${WRKSRC} ; ${GMAKE})

do-install:
	${MKDIR} ${DATADIRLIB}
	${INSTALL_DATA} ${WRKSRC}/resources.qrc ${DATADIRLIB}
	${INSTALL_SCRIPT} ${WRKSRC}/*.py ${DATADIRLIB}
	${LN} -sf ${DATADIRLIB}/${PORTNAME}.py ${PREFIX}/bin/${PORTNAME}
	${LN} -sf ${DATADIRLIB}/${PORTNAME}cli.py ${PREFIX}/bin/${PORTNAME}cli
	${LN} -sf ${DATADIRLIB}/${PORTNAME}run.py ${PREFIX}/bin/${PORTNAME}run
	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "translations images" ${DATADIR})

	${LN} -sf ${DATADIR}/images/swine32.png ${PREFIX}/share/pixmaps/${PORTNAME}.png
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/resources/*.desktop ${PREFIX}/share/applications/

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
