# ex:ts=8
# Ports collection makefile for:	libWPCG
# Date Created:			Nov 18, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libwpcg
PORTVERSION=	0.9.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.paassen.tmfweb.nl/
DISTNAME=	libWPCG-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A basic 2D/3D computer graphics library which uses OpenGL

USE_GCC=	3.4
USE_MESA=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib -lGL -lGLU -lglut"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 501103
# Work around bsd.port.mk bug: Does not currently set up MAKE_ENV for gcc 3.2 and 3.3
MAKE_ENV+=	CC="${CC}" CXX="${CXX}"
.endif

.include <bsd.port.post.mk>
