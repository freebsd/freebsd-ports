PORTNAME=	seqan3
DISTVERSION=	3.0.2-1195
DISTVERSIONSUFFIX=	-gee0dbcad
PORTREVISION=	2
CATEGORIES=	biology devel math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header-only library for biological sequence analysis

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

HPP_DEPENDS=	cereal>0:devel/cereal \
		range-v3>0:devel/range-v3
BUILD_DEPENDS=	${HPP_DEPENDS}
RUN_DEPENDS=	${HPP_DEPENDS} \
		coin-or-lemon>0:math/lemon

USES=		cmake localbase

USE_GITHUB=	yes
GH_ACCOUNT=	seqan
GH_TUPLE=	xxsds:sdsl-lite:9a0d567:sdsl_lite/submodules/sdsl-lite

NO_ARCH=	yes

post-install:
	@${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
