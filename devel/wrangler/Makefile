PORTNAME=	wrangler
DISTVERSIONPREFIX=	v
DISTVERSION=	1.19.12
PORTREVISION=	28
CATEGORIES=	devel

MAINTAINER=	kfv@kfv.io
COMMENT=	Cloudflare Workers CLI Tool
WWW=		https://developers.cloudflare.com/workers/cli-wrangler/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

DEPRECATED=	Deprecated upstream as of Aug 3, 2023
EXPIRATION_DATE=2025-07-31

LIB_DEPENDS=	libcurl.so:ftp/curl

USES=		cargo gmake ssl
USE_GITHUB=	yes
GH_ACCOUNT=	cloudflare

CARGO_FEATURES=	--no-default-features sys-openssl

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

# sys-info-0.9.1 crate fix: https://github.com/FillZpp/sys-info-rs/issues/80
post-patch:
	@${REINPLACE_CMD} \
	-e '/get_cpu/s|unsigned long|uint64_t|' \
	-e '/get_proc_total/s|unsigned long|uint64_t|' \
	${WRKSRC}/cargo-crates/sys-info-0.9.1/c/*.[ch]

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
