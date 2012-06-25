# New ports collection makefile for:	gns3
# Date created:		24 may 2009
# Whom:			Olivier Cochard-Labbe <olivier@cochard.me>
#
# $FreeBSD$
#

PORTNAME=	gns3
PORTVERSION=	0.8.2
CATEGORIES=	emulators
MASTER_SITES=	SF/gns-3/GNS3/${PORTVERSION}
DISTNAME=	GNS3-${PORTVERSION}-src

MAINTAINER=	olivier@cochard.me
COMMENT=	Graphical Cisco network simulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

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
MAN1=			${PORTNAME}.1

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

post-install:
.if ${PORT_OPTIONS:MMANPAGES}
	${INSTALL_MAN} ${WRKSRC}/docs/man/${MAN1} ${MANPREFIX}/man/man1
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/qemuwrapper/qemuwrapper.py \
		${PREFIX}/bin/qemuwrapper.py
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
