# New ports collection makefile for:	py-usb
# Date created:		2007-05-13
# Whom:			R.Mahmatkhanov <R.Mahmatkhanov@SKYLINK.ru>
#
# $FreeBSD$
#

PORTNAME=	pyusb
PORTVERSION=	0.4.2
CATEGORIES=	devel python
MASTER_SITES=	SF \
		${MASTER_SITE_BERLIOS}

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python wrapper around libusb

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/usb.so

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb

post-patch:
	${REINPLACE_CMD} 's,/usr/local,${LOCALBASE},' ${WRKSRC}/setup.py

.endif

.include <bsd.port.post.mk>
