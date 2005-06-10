# New ports collection makefile for:	audio/xmms-fxt
# Date created:			8 Jun 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	xmms-fxt
PORTVERSION=	0.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Surround/Echo effect plugin for XMMS

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
USE_GNOME=	gtk12

PLIST_FILES=	lib/xmms/Effect/libfxt.so

.include <bsd.port.mk>
