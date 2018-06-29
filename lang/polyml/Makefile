# Created by: Timothy Bourke <timbob@bigpond.com>
# $FreeBSD$

PORTNAME=	polyml
PORTVERSION=	5.7.1
DISTVERSIONPREFIX=	v
CATEGORIES=	lang
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Fast open-source implementation of Standard ML

LICENSE=	LGPL21

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libffi.so:devel/libffi

USES=		libtool pathfix pkgconfig

USE_GITHUB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-libffi --enable-shared
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	MOTIF

MOTIF_CONFIGURE_WITH=	x
MOTIF_USE=		motif

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++ ||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| modules||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
