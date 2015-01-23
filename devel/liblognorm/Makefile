# $FreeBSD$

PORTNAME=	liblognorm
PORTVERSION=	1.1.0
CATEGORIES=	devel net security
MASTER_SITES=	http://www.liblognorm.com/download/files/download/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Log normalizer

LICENSE=	GPLv2

LIB_DEPENDS=	libjson-c.so:${PORTSDIR}/devel/json-c \
		libestr.so:${PORTSDIR}/devel/libestr
BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx

USES=		pathfix pkgconfig libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

SUB_FILES=	pkg-message

# Try to fix parallel (-jX) builds
post-patch:
	@${REINPLACE_CMD} -e \
		'/^lognormalizer_DEPENDENCIES/s,=,= $$(lib_LTLIBRARIES),' \
			${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
