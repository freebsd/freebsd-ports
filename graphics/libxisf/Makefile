PORTNAME=	libxisf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.11
CATEGORIES=	graphics astro
MASTER_SITES=	https://gitea.nouspiro.space/nou/libXISF/archive/
DISTNAME=	${DISTVERSIONPREFIX}${DISTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Library to read and write XISF files produced by PixInsight
WWW=		https://gitea.nouspiro.space/nou/libXISF

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libzstd.so:archivers/zstd \
		libpugixml.so:textproc/pugixml

USES=		cmake compiler:c++17-lang pathfix pkgconfig
USE_LDCONFIG=	yes

CMAKE_OFF=	USE_BUNDLED_LIBS

TEST_TARGET=	test

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_SUB=	VERSION=${DISTVERSION}

.include <bsd.port.mk>
