PORTNAME=	polyml
PORTVERSION=	5.9.2
DISTVERSIONPREFIX=	v
CATEGORIES=	lang
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Fast open-source implementation of Standard ML
WWW=		https://www.polyml.org

LICENSE=	LGPL21

ONLY_FOR_ARCHS=	aarch64 amd64 i386

LIB_DEPENDS=	libffi.so:devel/libffi

USES=		libtool localbase pathfix pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-system-libffi --enable-shared

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	MOTIF GMP INTINF_AS_INT
OPTIONS_DEFAULT=GMP INTINF_AS_INT

INTINF_AS_INT_DESC=	Use IntInf.int as int type

GMP_LIB_DEPENDS=	libgmp.so:math/gmp
GMP_CONFIGURE_WITH=	gmp
INTINF_AS_INT_CONFIGURE_ENABLE=	intinf-as-int
MOTIF_USES=		motif xorg
MOTIF_USE=		xorg=x11,xext,xt
MOTIF_CONFIGURE_WITH=	x

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++ ||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| modules||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
