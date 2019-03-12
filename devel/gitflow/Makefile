# Created by: Nicolas Embriz <nbari@tequila.io>
# $FreeBSD$

PORTNAME=	gitflow
PORTVERSION=	1.12.1
PORTREVISION=	1
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

OPTIONS_DEFINE=	EXAMPLES

NO_BUILD=	yes
NO_ARCH=	yes
MAKE_ARGS=	prefix=${STAGEDIR}${PREFIX}

post-install:
	${MV} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
