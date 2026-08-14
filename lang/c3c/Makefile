PORTNAME=	c3c
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.3
CATEGORIES=	lang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Compiler for the C3 language
WWW=		https://c3-lang.org/ \
		https://github.com/c3lang/c3c

LICENSE=	LGPL3 MIT
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++17-lang llvm:19

USE_GITHUB=	yes
GH_ACCOUNT=	c3lang

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH="${LLVM_PREFIX};${LOCALBASE}"

OPTIONS_DEFINE=		CURL
OPTIONS_DEFAULT=	CURL

CURL_DESC=		Vendor library fetching via libcurl
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

post-stage:
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} lib/c3 -type f | ${SORT} >> ${TMPPLIST}

.include <bsd.port.mk>
