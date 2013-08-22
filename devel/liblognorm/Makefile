# $FreeBSD$

PORTNAME=	liblognorm
PORTVERSION=	0.3.5
CATEGORIES=	devel net security
MASTER_SITES=	http://www.liblognorm.com/download/files/download/

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Log normalizer

LICENSE=	GPLv2

LIB_DEPENDS=	libee.so:${PORTSDIR}/devel/libee \
		libestr.so:${PORTSDIR}/devel/libestr

USES=		pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

# Try to fix parallel (-jX) builds
post-patch:
	@${REINPLACE_CMD} -e \
		'/^lognormalizer_DEPENDENCIES/s,=,= $$(lib_LTLIBRARIES),' \
			${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
