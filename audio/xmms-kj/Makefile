# New ports collection makefile for:	xmms-kj
# Date created:				18 November 2002
# Whom:					Kay Lehmann
#
# $FreeBSD$
#

PORTNAME=	xmms-kj
PORTVERSION=	0.95
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.csse.monash.edu.au/~timf/
DISTFILES=	kint_xmms-${PORTVERSION}.tar.gz

MAINTAINER=	kay_lehmann@web.de
COMMENT=	This is a plugin that adds K-Joefol-Skinsupport to xmms

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes
USE_GNOME=	gtk12

do-build:
	cd ${WRKSRC} && make

do-install:
	cd ${WRKSRC} && make install

.include <bsd.port.mk>
