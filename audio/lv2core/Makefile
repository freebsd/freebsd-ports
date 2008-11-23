# New ports collection makefile for:	lv2core
# Date created:		2008-11-20
# Whom:			xaimus <xaimus@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	lv2core
PORTVERSION=	3.0
CATEGORIES=	audio
MASTER_SITES=	http://lv2plug.in/spec/

MAINTAINER=	xaimus@gmail.com
COMMENT=	LV2 Core Package

USE_BZIP2=	yes
USE_PYTHON_BUILD=	yes
USE_GNOME=	pkgconfig

do-configure:
	cd ${WRKSRC} && ${SETENV} DESTDIR=${LOCALBASE} ./waf configure

do-build:
	cd ${WRKSRC} && ./waf build

do-install:
	cd ${WRKSRC} && ./waf install

.include <bsd.port.mk>
