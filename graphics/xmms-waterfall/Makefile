# New ports collection makefile for:	graphics/xmms-waterfall
# Date created:			17 Jun 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	waterfall
PORTVERSION=	0.11
CATEGORIES=	graphics
MASTER_SITES=	http://www.aigeek.com/waterfall/
PKGNAMEPREFIX=	xmms-

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Yet another XMMS spectrum analyzer

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
USE_INC_LIBTOOL_VER=	13

PLIST_FILES=	lib/xmms/Visualization/libwaterfall.so

post-patch:
	@${REINPLACE_CMD} -e 's|-O2|${CFLAGS}|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
