PORTNAME=	gitflow
PORTVERSION=	1.12.3
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	nbari@tequila.io
COMMENT=	Git extensions to provide high-level repository operations
WWW=		https://github.com/petervanderdoes/gitflow-avh

LICENSE=	BSD2CLAUSE LGPL21
LICENSE_COMB=	multi

DEPRECATED=	Upstream repo archived Jun 19, 2023
EXPIRATION_DATE=2024-12-31

RUN_DEPENDS=	getopt>=0:misc/getopt

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	petervanderdoes
GH_PROJECT=	${PORTNAME}-avh

NO_BUILD=	yes
NO_ARCH=	yes
MAKE_ARGS=	prefix=${STAGEDIR}${PREFIX}

OPTIONS_DEFINE=	EXAMPLES

post-install:
	${MV} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
