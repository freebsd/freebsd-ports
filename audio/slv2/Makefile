# New ports collection makefile for:	slv2
# Date created:		2008-11-25
# Whom:			xaimus <xaimus@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	slv2
PORTVERSION=	0.6.1
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	xaimus@gmail.com
COMMENT=	LV2 Application Support Library

LIB_DEPENDS=	rdf.0:${PORTSDIR}/textproc/redland \
		jack.0:${PORTSDIR}/audio/jack
BUILD_DEPENDS=	${LOCALBASE}/include/lv2.h:${PORTSDIR}/audio/lv2core

USE_BZIP2=	yes
USE_PYTHON_BUILD=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes

do-configure:
	cd ${WRKSRC} && ${SETENV} DESTDIR=${LOCALBASE} ./waf configure

do-build:
	cd ${WRKSRC} && ./waf build

do-install:
	cd ${WRKSRC} && ./waf install

.include <bsd.port.mk>
