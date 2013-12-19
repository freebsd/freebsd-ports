# $FreeBSD$

PORTNAME=	liblognorm
PORTVERSION=	1.0.0
CATEGORIES=	devel net security
MASTER_SITES=	http://www.liblognorm.com/download/files/download/

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Log normalizer

LICENSE=	GPLv2

LIB_DEPENDS=	libjson.so:${PORTSDIR}/devel/json-c \
		libestr.so:${PORTSDIR}/devel/libestr

USES=		pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

# Try to fix parallel (-jX) builds
post-patch:
	@${REINPLACE_CMD} -e \
		'/^lognormalizer_DEPENDENCIES/s,=,= $$(lib_LTLIBRARIES),' \
			${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
