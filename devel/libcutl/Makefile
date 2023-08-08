PORTNAME=	libcutl
PORTVERSION=	1.10.0
PORTREVISION=	21
CATEGORIES=	devel
MASTER_SITES=	https://www.codesynthesis.com/download/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	rakuco@FreeBSD.org
COMMENT=	C++ utility library with generic and independent components
WWW=		https://www.codesynthesis.com/projects/libcutl/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_sparc64=	Does not build: cannot configure with boost

LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libexpat.so:textproc/expat2

USES=		compiler:c++11-lib libtool
# libcutl 1.10.0 is not compatible with C++17, which is the default since clang
# 16. This means ports depending on it also need to use at most C++14.
USE_CXXSTD=	c++11
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

# The checks for external boost and external expat are quite limited and do not
# add the ${LOCALBASE} paths correctly (libboost.m4 uses wrong paths and
# libexpat.m4 does nothing at all).
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--disable-static \
		--with-boost=${LOCALBASE} \
		--with-external-boost \
		--with-external-expat \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

OPTIONS_DEFINE=	DOCS

post-patch:
# Avoid conflict with C++20 <version> by adding .txt suffix
	@${MV} ${WRKSRC}/version ${WRKSRC}/version.txt
	@${REINPLACE_CMD} -i .c++20 '/doc_DATA/s/version/&.txt/' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
