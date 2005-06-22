# New ports collection makefile for:	audio/xmms-efxmms
# Date created:			17 Jun 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	xmms-efxmms
PORTVERSION=	0.0.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	efxmms
DISTNAME=	EFXmms-${PORTVERSION}

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Send the XMMS audio output through a queue of multiple effect plugins

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_INC_LIBTOOL_VER=	13

PLIST_FILES=	lib/xmms/Effect/libefx.so

.include <bsd.port.mk>
