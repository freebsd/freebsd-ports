PORTNAME=	osmium-tool
DISTVERSIONPREFIX=	v
DISTVERSION=	1.19.0
CATEGORIES=	astro geography

MAINTAINER=	ianthetechie@gmail.com
COMMENT=	Command line tool for working with OpenStreetMap data using libosmium
WWW=		https://osmcode.org/osmium-tool/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	hs-pandoc>0:textproc/hs-pandoc \
		nlohmann-json>=3.0.0:devel/nlohmann-json \
		protozero>=1.6.3:devel/protozero \
		libosmium>=2.20:astro/libosmium
LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs \
		libexpat.so:textproc/expat2

USES=		cmake:testing
USE_GITHUB=	yes
GH_ACCOUNT=	osmcode

PORTEXAMPLES=		extract-example-config/*
OPTIONS_DEFINE=		EXAMPLES LZ4
OPTIONS_DEFAULT=	EXAMPLES LZ4

LZ4_CMAKE_BOOL=	WITH_LZ4

LZ4_DESC=		Build with support for LZ4 compression of PBF files
LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTEXAMPLES}" ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
