# New ports collection makefile for:	caps-plugins
# Date created:		2007-03-06
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	caps-plugins
PORTVERSION=	0.4.3
CATEGORIES=	audio
MASTER_SITES=	http://quitte.de/dsp/
DISTNAME=	caps_${PORTVERSION}

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	The C* Audio Plugin Suite

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/caps-${PORTVERSION}
USE_GMAKE=	yes
CFLAGS+=	-fPIC

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
CFLAGS+=	-O2 -ffast-math -funroll-loops
.endif

.include <bsd.port.mk>
