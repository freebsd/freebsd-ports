# New ports collection makefile for:	bugle
# Date created:			Jun 8, 2004
# Whom:				Erik Greenwald <erik@smluc.org>
#
# $FreeBSD$
#

PORTNAME=	bugle
PORTVERSION=	0.0.20040609
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bugle

MAINTAINER=	erik@smluc.org
COMMENT=	A debugging library for OpenGL

USE_GCC=	3.3
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LIBS="-L${X11BASE}/lib"

.include <bsd.port.mk>
