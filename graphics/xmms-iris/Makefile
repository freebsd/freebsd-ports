# New ports collection makefile for:	xmms-iris
# Date created:				25 Apr 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	iris
PORTVERSION=	0.9
CATEGORIES=	graphics
MASTER_SITES=	http://cdelfosse.free.fr/xmms-iris/
PKGNAMEPREFIX=	xmms-

MAINTAINER=	dyeske@yahoo.com

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/audio/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/audio/xmms

GNU_CONFIGURE=	yes
USE_GLIB=	yes
USE_GTK=	yes
USE_GMAKE=	yes
USE_MESA=	yes
USE_X_PREFIX=	yes

.include <bsd.port.mk>
