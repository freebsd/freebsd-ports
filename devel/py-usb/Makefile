# New ports collection makefile for:	py-usb
# Date created:		2007-05-13
# Whom:			R.Mahmatkhanov <R.Mahmatkhanov@SKYLINK.ru>
#
# $FreeBSD$
#

PORTNAME=	pyusb
PORTVERSION=	0.4.1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	R.Mahmatkhanov@SKYLINK.ru
COMMENT=	Python wrapper around libusb

RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/usb.so

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	${LOCALBASE}/lib/libusb.so:${PORTSDIR}/devel/libusb
.endif

.include <bsd.port.post.mk>
