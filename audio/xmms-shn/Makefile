# New ports collection makefile for:   shntool
# Date created:        2 November 2000
# Whom:                Bill Fenner <fenner@FreeBSD.Org>
#
# $FreeBSD$
#

PORTNAME=	xmms-shn
PORTVERSION=	2.1
CATEGORIES=	audio
MASTER_SITES=	http://sdf.lonestar.org/~jason/shn-utils/xmms-shn/source/

MAINTAINER=	fenner@FreeBSD.Org

LIB_DEPENDS=	glib12.3:${PORTSDIR}/devel/glib12 \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
BUILD_DEPENDS=	xmms-config:${PORTSDIR}/audio/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/audio/xmms

USE_X_PREFIX=	yes
USE_AUTOCONF=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
