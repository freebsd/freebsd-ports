# New ports collection makefile for:	gltt
# Date created:		12 Aug 2002
# Whom:			Igor Pokrovsky <tiamat@telegraph.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	gltt
PORTVERSION=	2.5.2
CATEGORIES=	graphics
MASTER_SITES=	http://gltt.sourceforge.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TrueType fonts rendering using OpenGL

LIB_DEPENDS=	ttf.4:${PORTSDIR}/print/freetype

USE_GMAKE=	yes
USE_MESA=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--x-includes=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib \
		--with-ttf-includes=${LOCALBASE}/include/freetype1 \
		--with-ttf-libraries=${LOCALBASE}/lib \
		--with-gl-includes=${X11BASE}/include \
		--with-gl-libraries=${X11BASE}/lib \
		--with-glut-includes=${X11BASE}/include \
		--with-glut-libraries=${X11BASE}/lib
CONFIGURE_ENV=	CPPFLAGS=-I${X11BASE}/include
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
