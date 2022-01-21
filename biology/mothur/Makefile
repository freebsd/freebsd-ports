PORTNAME=	mothur
DISTVERSIONPREFIX=	v.
DISTVERSION=	1.47.0
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software for bioinformatics of the microbial ecology community

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang gmake localbase readline
USE_GITHUB=	yes

MAKE_ARGS=	INSTALL_DIR=${STAGEDIR}${PREFIX}/bin

ALL_TARGET=	${PORTNAME}

BINARY_ALIAS=	g++=${CXX}

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
