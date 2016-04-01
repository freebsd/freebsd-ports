# Created by: Olivier Cochard-Labbe <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gns3
PORTVERSION=	0.8.7
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/gns-3/GNS3/${PORTVERSION}
DISTNAME=	GNS3-${PORTVERSION}-src

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Graphical Cisco network simulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:x11-toolkits/py-qt4-gui \
		${PYTHON_SITELIBDIR}/PyQt4/QtSvg.so:graphics/py-qt4-svg \
		${PYTHON_SITELIBDIR}/PyQt4/QtNetwork.so:net/py-qt4-network \
		dynamips:emulators/dynamips-community \
		dynagen:emulators/dynagen \
		xdotool:x11/xdotool

WRKSRC=		${WRKDIR}/${PORTNAME}-legacy-GNS3-${PORTVERSION}

USES=		cpe python
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	GNS3
NO_ARCH=	yes

DESKTOP_ENTRIES=	"GNS3" "${COMMENT}" "" "${PORTNAME}" "System;Emulator;" true

PLIST_SUB=	PYTHON_VERSION=${PYTHON_VERSION:S/python//} \
		VERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' -e 's|/share/man|/man|g' ${WRKSRC}/setup.py

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/man/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
