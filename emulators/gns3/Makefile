# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	gns3
PORTVERSION=	0.8.7
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/gns-3/GNS3/${PORTVERSION}
DISTNAME=	GNS3-${PORTVERSION}-src

MAINTAINER=	olivier@cochard.me
COMMENT=	Graphical Cisco network simulator

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_SITELIBDIR}/PyQt4/QtSvg.so:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_SITELIBDIR}/PyQt4/QtNetwork.so:${PORTSDIR}/net/py-qt4-network \
		dynamips:${PORTSDIR}/emulators/dynamips-community \
		dynagen:${PORTSDIR}/emulators/dynagen \
		xdotool:${PORTSDIR}/x11/xdotool

WRKSRC=	${WRKDIR}/${PORTNAME}-legacy-GNS3-${PORTVERSION}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	GNS3

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
