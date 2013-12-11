# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	openuniverse
DISTVERSION=	1.0beta3
PORTREVISION=	8
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.0beta3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL Solar System simulator for X Window System

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg

USE_GL=		glut

USES=		gmake
USE_XORG=	sm ice xmu xi xext x11
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--includedir="${LOCALBASE}/include" \
		--libdir="${LOCALBASE}/lib" \

CONFIGURE_ENV=	LIBS="-lcompat"
CPPFLAGS+=	-I${LOCALBASE}/include/GL -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lm

.include <bsd.port.mk>
