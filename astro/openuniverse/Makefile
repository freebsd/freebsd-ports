# New ports collection makefile for:	openuniverse
# Date created:				4 August 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	openuniverse
PORTVERSION=	1.0.b3
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	openuniverse
DISTNAME=	${PORTNAME}-1.0beta3

MAINTAINER=	trevor@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_MESA=	yes

CONFIGURE_ARGS=	--includedir="${LOCALBASE}/include" \
		--libdir="${LOCALBASE}/lib" \

CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include -I${X11BASE}/include/GL -I${LOCALBASE}/include" \
		LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib -lm"  \
		LIBS="-lcompat" PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"

USE_X_PREFIX=	yes

.include <bsd.port.mk>
