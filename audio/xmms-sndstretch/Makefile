# New ports collection makefile for:	xmms-sndstretch
# Date created:				10 November 2001
# Whom:					Edwin Mons <ports@edwinm.ik.nu>
#
# $FreeBSD$
#

PORTNAME=	sndstretch
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/harpin_floh/mysoft/
PKGNAMEPREFIX=	xmms-
DISTNAME=	sndstretch_xmms-${PORTVERSION}

MAINTAINER=	ports@edwinm.ik.nu
COMMENT=	Plugin for xmms to change the pitch and/or speed

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

WRKSRC=		${WRKDIR}/sndstretch_xmms

USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_X_PREFIX=	yes
MAKE_ENV+=	GTK_CONFIG="${GTK_CONFIG}" PTHREAD_LIBS=${PTHREAD_LIBS}

post-extract:
	(cd ${WRKSRC}; ${MAKE} clean)

.include <bsd.port.mk>
