# New ports collection makefile for:	openuniverse
# Date created:				4 August 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=		openuniverse
PORTVERSION=		1.0beta3
CATEGORIES=		astro
MASTER_SITES=		http://download.sourceforge.net/openuniverse/

MAINTAINER=		will@FreeBSD.org

LIB_DEPENDS=		jpeg.9:${PORTSDIR}/graphics/jpeg \
			GL.14:${PORTSDIR}/graphics/Mesa3

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--includedir="${LOCALBASE}/include" \
		--libdir="${LOCALBASE}/lib" \

CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include -I${X11BASE}/include/GL -I${LOCALBASE}/include" \
		LDFLAGS="-L${X11BASE}/lib -L${LOCALBASE}/lib -lm"  \
		LIBS="-lcompat"

USE_X_PREFIX=		yes

.include <bsd.port.mk>
