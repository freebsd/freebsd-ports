# New ports collection makefile for:	gltt
# Date created:		12 Aug 2002
# Whom:			Igor Pokrovsky <tiamat@telegraph.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	gltt
PORTVERSION=	2.5.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://gltt.sourceforge.net/download/

MAINTAINER=	tiamat@comset.net
COMMENT=	TrueType fonts rendering using OpenGL

USE_X_PREFIX=	yes
USE_MESA=	yes
USE_FREETYPE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LIBS="-L${X11BASE}/lib"
CONFIGURE_ARGS=	--with-ttf-includes=${LOCALBASE}/include/freetype1 \
		--with-ttf-libraries=${LOCALBASE}/lib \
		--with-gl-includes=${X11BASE}/include \
		--with-gl-libraries=${X11BASE}/lib \
		--with-glut-includes=${X11BASE}/include \
		--with-glut-libraries=${X11BASE}/lib
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
