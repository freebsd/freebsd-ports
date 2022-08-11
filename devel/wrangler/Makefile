PORTNAME=	wrangler
DISTVERSIONPREFIX=	v
DISTVERSION=	1.19.12
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	antranigv@freebsd.am
COMMENT=	Cloudflare Workers CLI Tool

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BROKEN_i386=	fails to build: error occurred: Command "cc" ... with args "cc" did not execute successfully (status code exit status: 1)

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cargo gmake ssl
USE_GITHUB=	yes
GH_ACCOUNT=	cloudflare

CARGO_FEATURES=	--no-default-features sys-openssl

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
