# New ports collection makefile for:	xmms-fc
# Date created:				8 Jan 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-fc
PORTVERSION=	0.5.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A XMMS future composer input plugin

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Input/libfc.so
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk12

.include <bsd.port.mk>
