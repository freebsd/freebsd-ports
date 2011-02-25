# New ports collection makefile for:	gns3
# Date created:		24 may 2009
# Whom:			Olivier Cochard-Labbe <olivier@cochard.me>
#
# $FreeBSD$
#

PORTNAME=	gns3
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/gns-3/GNS3/${PORTVERSION}
DISTNAME=	GNS3-${PORTVERSION}-src

MAINTAINER=	olivier@cochard.me
COMMENT=	Graphical Cisco network simulator

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui \
		${PYTHON_SITELIBDIR}/PyQt4/QtSvg.so:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_SITELIBDIR}/PyQt4/QtNetwork.so:${PORTSDIR}/net/py-qt4-network \
		dynamips:${PORTSDIR}/emulators/dynamips-devel \
		dynagen:${PORTSDIR}/emulators/dynagen \
		qemu>=0.11:${PORTSDIR}/emulators/qemu

USE_PYTHON=		2.5+
USE_PYDISTUTILS=	YES
PYDISTUTILS_PKGNAME=	GNS3
WRKSRC=			${WRKDIR}/${DISTNAME}
MAN1=			gns3.1

post-install:
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/docs/man/gns3.1 ${MANPREFIX}/man/man1
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/qemuwrapper/qemuwrapper.py ${PREFIX}/bin/qemuwrapper.py

.include <bsd.port.mk>
