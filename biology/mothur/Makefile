PORTNAME=	mothur
DISTVERSIONPREFIX=	v
DISTVERSION=	1.48.5
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software for bioinformatics of the microbial ecology community
WWW=		https://www.mothur.org/ \
		https://github.com/mothur/mothur

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang gmake localbase readline
USE_GITHUB=	yes
#USE_CXXSTD=	c++11 # not all C++ files are compiled with -std=c++11 which causes failure in addtargets2.cpp due to a collision of the 'byte' symbol with std::byte

MAKE_ARGS=	INSTALL_DIR=${STAGEDIR}${PREFIX}/bin

ALL_TARGET=	${PORTNAME}

BINARY_ALIAS=	g++=${CXX}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
USES+=	llvm:max=15
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
