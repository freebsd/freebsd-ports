# New ports collection makefile for:	gltt
# Date created:		12 Aug 2002
# Whom:			Igor Pokrovsky <tiamat@telegraph.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	gltt
PORTVERSION=	2.5.2
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	http://gltt.sourceforge.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TrueType fonts rendering using OpenGL

USE_AUTOTOOLS=	libtool
USE_GL=		gl glut
USE_FREETYPE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--with-ttf-includes=${LOCALBASE}/include/freetype1 \
		--with-ttf-libraries=${LOCALBASE}/lib \
		--with-gl-includes=${LOCALBASE}/include \
		--with-gl-libraries=${LOCALBASE}/lib \
		--with-glut-includes=${LOCALBASE}/include \
		--with-glut-libraries=${LOCALBASE}/lib
USE_LDCONFIG=	yes

.include <bsd.port.mk>
