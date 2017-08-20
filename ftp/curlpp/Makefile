# Created by: ijliao
# $FreeBSD$

PORTNAME=	curlpp
PORTVERSION=	0.8.1
DISTVERSIONPREFIX=	v
CATEGORIES=	ftp

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ wrapper for libcurl

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

BROKEN_powerpc64=	fails to configure: error: A compiler with support for C++11 language features is required

LIB_DEPENDS=	libcurl.so:ftp/curl

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_LDCONFIG=	yes
USES=		cmake localbase pathfix

PORTDOCS=	*
PORTEXAMPLES=	*

GH_ACCOUNT=	jpbarrette
USE_GITHUB=	yes

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/guide.pdf ${STAGEDIR}${DOCSDIR}/

x-post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/README ${WRKSRC}/examples/example*.cpp ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
