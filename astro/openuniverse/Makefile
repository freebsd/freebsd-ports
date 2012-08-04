# New ports collection makefile for:	openuniverse
# Date created:				4 August 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	openuniverse
DISTVERSION=	1.0beta3
PORTREVISION=	8
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.0beta3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenGL Solar System simulator for X Window System

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg

USE_GL=		glut

USE_XORG=	sm ice xmu xi xext x11
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--includedir="${LOCALBASE}/include" \
		--libdir="${LOCALBASE}/lib" \

CONFIGURE_ENV=	LIBS="-lcompat" PTHREAD_LIBS="${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include/GL -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lm
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"

.include <bsd.port.mk>
