# $FreeBSD$

PORTNAME=	tabixpp
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-10
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g6bbe690
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	C++ wrapper to tabix indexer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhts.so:biology/htslib

USES=		localbase:ldflags
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	ekg

# Disable bundled htslib
MAKE_ENV=	HTS_HEADERS='' HTS_LIB=''
MAKEFILE=	${FILESDIR}/Makefile
INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/tabix++ \
		include/tabix.hpp \
		lib/libtabix.a \
		lib/libtabix.so \
		lib/libtabix.so.1

post-install:
	${RLN} ${STAGEDIR}${PREFIX}/lib/libtabix.so.1 \
		${STAGEDIR}${PREFIX}/lib/libtabix.so

.include <bsd.port.mk>
