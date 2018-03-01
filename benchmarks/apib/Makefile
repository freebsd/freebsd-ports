# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apib
PORTVERSION=	1.0
CATEGORIES=	benchmarks www

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple, fast HTTP performance-testing tool

LICENSE=	APACHE20

LIB_DEPENDS=	libapr-1.so:devel/apr1

USE_GITHUB=	yes
GH_ACCOUNT=	apigee
GH_TAGNAME=	7e8dea9

USES=		localbase ssl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	APR_LOC="${LOCALBASE}/include/apr-1"

PLIST_FILES=	bin/apib bin/apibmon
PORTEXAMPLES=	env.sh pivot run.sh rungroup.sh tojson

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apib ${WRKSRC}/apibmon \
		${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samplescripts/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
