# New ports collection makefile for:	xmms-sndstretch
# Date created:				10 November 2001
# Whom:					Edwin Mons <ports@edwinm.ik.nu>
#
# $FreeBSD$
#

PORTNAME=	sndstretch
PORTVERSION=	0.5
CATEGORIES=	audio
MASTER_SITES=	http://www.geocities.com/harpin_floh/mysoft/
PKGNAMEPREFIX=	xmms-
DISTNAME=	sndstretch_xmms-${PORTVERSION}

MAINTAINER=	ports@edwinm.ik.nu

LIB_DEPENDS=	xmms.3:${PORTSDIR}/audio/xmms

WRKSRC=		${WRKDIR}/sndstretch_xmms

USE_GTK=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
MAKE_ENV+=	GTK_CONFIG="${GTK_CONFIG}" PTHREAD_LIBS=${PTHREAD_LIBS}

post-extract:
	(cd ${WRKSRC}; ${MAKE} clean)

.include <bsd.port.mk>
