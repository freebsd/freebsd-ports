# New ports collection makefile for:	py-usb
# Date created:		2007-05-13
# Whom:			R.Mahmatkhanov <R.Mahmatkhanov@SKYLINK.ru>
#
# $FreeBSD$
#

PORTNAME=	usb
PORTVERSION=	0.4.3
CATEGORIES=	devel python
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	py${PORTNAME}/PyUSB%200.x/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	sbrabez@gmail.com
COMMENT=	Python wrapper around libusb

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	py${PORTNAME}

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb

post-patch:
	${REINPLACE_CMD} 's,/usr/local,${LOCALBASE},' ${WRKSRC}/setup.py

.endif

post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
