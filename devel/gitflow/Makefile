# Created by: Nicolas Embriz <nbari@tequila.io>
# $FreeBSD$

PORTNAME=	gitflow
PORTVERSION=	1.12.3
CATEGORIES=	devel

MAINTAINER=	nbari@tequila.io
COMMENT=	Git extensions to provide high-level repository operations

LICENSE=	BSD2CLAUSE LGPL21
LICENSE_COMB=	multi

RUN_DEPENDS=	${LOCALBASE}/bin/getopt:misc/getopt

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
