# New ports collection makefile for:	libosmesa
# Date created:				9 April 2010
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	libosmesa
PORTVERSION=	7.11.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/${PORTVERSION}/
DISTNAME=	MesaLib-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Off-Screen Mesa implementation of the OpenGL API

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
    		talloc.2:${PORTSDIR}/devel/talloc
BUILD_DEPENDS=	makedepend:${PORTSDIR}/devel/makedepend \
		bison:${PORTSDIR}/devel/bison

CONFLICTS=	mesagl-mangled-*

USE_BZIP2=	yes
USE_GCC=	4.2+
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-driver=osmesa --with-osmesa-bits=32 \
		--with-gallium-drivers= --disable-asm \
		--disable-egl \
		--includedir=${PREFIX}/include/Mesa
CFLAGS+=	-I${LOCALBASE}/include -fPIC
CPPFLAGS=	${CFLAGS}

WRKSRC=		${WRKDIR}/Mesa-${PORTVERSION}

.include <bsd.port.mk>
