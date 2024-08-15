PORTNAME=	apib
DISTVERSIONPREFIX=	${PORTNAME:tu}_
DISTVERSION=	1_2_1
DISTVERSIONSUFFIX=	_RC1
PORTREVISION=	6
CATEGORIES=	benchmarks www

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple and fast HTTP performance testing tool
WWW=		https://github.com/apigee/apib

LICENSE=	APACHE20

LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libev.so:devel/libev \
		libgtest.so:devel/googletest \
		libhttp_parser.so:www/http-parser

USES=		cmake:testing compiler:c++17-lang localbase:ldflags ssl
USE_GITHUB=	yes
GH_ACCOUNT=	apigee

PLIST_FILES=	bin/apib bin/apibmon bin/testserver
PORTEXAMPLES=	env.sh pivot run.sh rungroup.sh tojson

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samplescripts/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
