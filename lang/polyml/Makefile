# Created by: Timothy Bourke <timbob@bigpond.com>
# $FreeBSD$

PORTNAME=	polyml
PORTVERSION=	5.8
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	lang
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Fast open-source implementation of Standard ML

LICENSE=	LGPL21

ONLY_FOR_ARCHS=	aarch64 amd64 i386

LIB_DEPENDS=	libffi.so:devel/libffi

USES=		libtool localbase pathfix pkgconfig

USE_GITHUB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-libffi --enable-shared
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	MOTIF GMP INTINF_AS_INT
OPTIONS_DEFAULT=GMP INTINF_AS_INT

MOTIF_CONFIGURE_WITH=	x
MOTIF_USE=		motif

GMP_CONFIGURE_WITH=	gmp
GMP_LIB_DEPENDS=	libgmp.so:math/gmp

INTINF_AS_INT_DESC=	Use IntInf.int as int type
INTINF_AS_INT_CONFIGURE_ENABLE=	intinf-as-int

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++ ||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| modules||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
