# ex:ts=8
# Ports collection makefile for:	libWPCG
# Date Created:			Nov 18, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libwpcg
PORTVERSION=	0.9.3
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.paassen.tmfweb.nl/
DISTNAME=	libWPCG-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A basic 2D/3D computer graphics library which uses OpenGL

USE_GCC=	3.4
USE_GL=		glut
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lGL -lGLU -lglut"

.include <bsd.port.mk>
