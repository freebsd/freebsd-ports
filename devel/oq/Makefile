PORTNAME=	oq
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.20
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	hoanga@gmail.com
COMMENT=	Terminal OpenAPI Spec viewer
WWW=		https://github.com/plutov/oq

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.25+,modules
GO_MODULE=	github.com/plutov/oq

PLIST_FILES=	bin/${PORTNAME}
PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
