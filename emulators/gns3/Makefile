# New ports collection makefile for:	gns3
# Date created:		24 may 2009
# Whom:			Olivier Cochard-Labbe <olivier@cochard.me>
#
# $FreeBSD$
#

PORTNAME=	gns3
PORTVERSION=	0.7.4
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
		qemu:${PORTSDIR}/emulators/qemu

USE_PYTHON=		2.6+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	GNS3
MAN1=			gns3.1

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} \
		"s|%%PREFIX%%|${PREFIX}|;s|%%LOCALBASE%%|${LOCALBASE}|" \
		${WRKSRC}/src/GNS3/Ui/ConfigurationPages/*.py

.if !defined(NO_IGNORE)
pre-configure:
	@if qemu -help | ${GREP} -q -- "-net udp" >/dev/null 2>&1; then \
		: ; \
	else \
		${ECHO_MSG} "===>  ${PKGNAME} must be used with a gns3 patched qemu"; exit 1; \
	fi
.endif

post-install:
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/docs/man/gns3.1 ${MANPREFIX}/man/man1
.endif
	${INSTALL_SCRIPT} ${WRKSRC}/qemuwrapper/qemuwrapper.py \
		${PREFIX}/bin/qemuwrapper.py
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
