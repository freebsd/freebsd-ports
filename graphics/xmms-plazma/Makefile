# New ports collection makefile for:	xmms-plazma
# Date created:				15 Oct 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	xmms-plazma
DISTVERSION=	0.0.7
CATEGORIES=	graphics
MASTER_SITES=	http://membres.lycos.fr/diablolight/

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Plazma is an XMMS visualization plugin

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_GL=		yes
USE_GNOME=	gtk12
USE_SDL=	sdl

USE_INC_LIBTOOL_VER=13

PLIST_FILES=	lib/xmms/Visualization/libplazma.so

.include <bsd.port.mk>
