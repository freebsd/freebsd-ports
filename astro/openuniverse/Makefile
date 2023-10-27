PORTNAME=	openuniverse
DISTVERSION=	1.0beta3
PORTREVISION=	14
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.0beta3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL Solar System simulator for X Window System
WWW=		https://openuniverse.sourceforge.net/

USES=		gl gmake jpeg localbase xorg
USE_CXXSTD=	c++14
USE_GL=		glut
USE_XORG=	sm ice xmu xi xext x11

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--includedir="${LOCALBASE}/include" \
		--libdir="${LOCALBASE}/lib" \

CPPFLAGS+=	-I${LOCALBASE}/include/GL
LIBS+=		-lm -lcompat

.include <bsd.port.mk>
