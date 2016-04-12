# Created by: Nicolas Embriz <nbari@dalmp.com>
# $FreeBSD$

PORTNAME=	gitflow
PORTVERSION=	1.8.0
CATEGORIES=	devel

MAINTAINER=	nbari@dalmp.com
COMMENT=	Git extensions to provide high-level repository operations

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/bin/getopt:misc/getopt

USE_GITHUB=	yes
GH_ACCOUNT=	nbari

OPTIONS_DEFINE=	EXAMPLES

USES=		tar:bzip2 gmake

NO_BUILD=	yes
MAKE_ARGS=	prefix=${STAGEDIR}${PREFIX}

post-install:
	${MV} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
