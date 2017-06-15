# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	openuniverse
DISTVERSION=	1.0beta3
PORTREVISION=	11
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.0beta3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL Solar System simulator for X Window System

USE_GL=		glut

USES=		gmake jpeg
USE_XORG=	sm ice xmu xi xext x11
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--includedir="${LOCALBASE}/include" \
		--libdir="${LOCALBASE}/lib" \

CPPFLAGS+=	-I${LOCALBASE}/include/GL -I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm -lcompat

.include <bsd.port.mk>
