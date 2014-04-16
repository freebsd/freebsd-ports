# Created by: Igor Pokrovsky <tiamat@telegraph.spb.ru>
# $FreeBSD$

PORTNAME=	gltt
PORTVERSION=	2.5.2
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	http://gltt.sourceforge.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TrueType fonts rendering using OpenGL

LIB_DEPENDS=	libttf.so:${PORTSDIR}/print/freetype

USES=		gmake
USE_AUTOTOOLS=	libtool
USE_GL=		gl glut
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
