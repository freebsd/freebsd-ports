PORTNAME=	openuniverse
DISTVERSION=	1.0beta3
PORTREVISION=	15
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.0beta3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL Solar System simulator for X Window System
WWW=		https://openuniverse.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gl gmake jpeg localbase xorg
USE_CXXSTD=	c++14
USE_GL=		gl glu glut
USE_XORG=	sm ice xmu xi xext x11

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--includedir="${LOCALBASE}/include" \
		--libdir="${LOCALBASE}/lib" \

CPPFLAGS+=	-I${LOCALBASE}/include/GL
LIBS+=		-lm -lcompat -lutil

.include <bsd.port.mk>
