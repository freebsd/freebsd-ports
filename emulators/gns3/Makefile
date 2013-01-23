# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	gns3
PORTVERSION=	0.8.3.1
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/gns-3/GNS3/${PORTVERSION}
DISTNAME=	GNS3-${PORTVERSION}-src

MAINTAINER=	olivier@cochard.me
COMMENT=	Graphical Cisco network simulator

LICENSE=	GPLv2

BUILD_DEPENDS=	qemu:${PORTSDIR}/emulators/qemu
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_SITELIBDIR}/PyQt4/QtSvg.so:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_SITELIBDIR}/PyQt4/QtNetwork.so:${PORTSDIR}/net/py-qt4-network \
		dynamips:${PORTSDIR}/emulators/dynamips-community \
		dynagen:${PORTSDIR}/emulators/dynagen \
		xdotool:${PORTSDIR}/x11/xdotool

USE_PYTHON=		2.6+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	GNS3

DESKTOP_ENTRIES=	"GNS3" "${COMMENT}" "" "${PORTNAME}" "System;Emulator;" "true"

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMANPAGES}
MAN1=	${PORTNAME}.1
.endif

post-install:
.if ${PORT_OPTIONS:MMANPAGES}
	${INSTALL_MAN} ${WRKSRC}/docs/man/${MAN1} ${MAN1PREFIX}/man/man1
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
