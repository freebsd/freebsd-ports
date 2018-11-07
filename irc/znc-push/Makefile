# $FreeBSD$

PORTNAME=	znc-push
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0-165
DISTVERSIONSUFFIX=	-g0a36b1c
CATEGORIES=	irc

MAINTAINER=	dor.bsd@xm0.uk
COMMENT=	Push notification service module for ZNC

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	znc:irc/znc
LIB_DEPENDS=	libicudata.so:devel/icu
RUN_DEPENDS=	znc:irc/znc

USES=	gmake ssl

USE_GITHUB=	yes
GH_ACCOUNT=	jreese

MAKE_ENV=	version=${PORTVERSION}

PLIST_FILES=	lib/znc/push.so
PORTDOCS=	*.md

OPTIONS_DEFINE=	CURL DOCS

CURL_DESC=	Use curl for HTTP requests
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_MAKE_ENV=	curl=yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/znc
	${INSTALL_PROGRAM} ${WRKSRC}/push.so ${STAGEDIR}${PREFIX}/lib/znc/push.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/znc/push.so

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${WRKSRC}/doc/*.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
