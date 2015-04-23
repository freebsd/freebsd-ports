# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	isl
PORTVERSION=	0.14.1
CATEGORIES=	devel
MASTER_SITES=	http://isl.gforge.inria.fr/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Integer Set Library

LICENSE=	MIT

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp

CONFIGURE_ARGS+=	--with-gmp-prefix=${LOCALBASE}
GNU_CONFIGURE=	yes
USES=		libtool tar:xz
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's@pkgconfig_libdir=.*@pkgconfig_libdir=$${prefix}/libdata/pkgconfig@' ${WRKSRC}/configure

.include <bsd.port.mk>
