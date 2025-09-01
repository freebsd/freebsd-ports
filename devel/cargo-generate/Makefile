PORTNAME=	cargo-generate
DISTVERSIONPREFIX=	v
DISTVERSION=	0.23.4
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Quickly generate Rust project templates from existing git repositories
WWW=		https://github.com/ashleygwilliams/cargo-generate

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo localbase ssl
USE_GITHUB=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md CODE_OF_CONDUCT.md CONTRIBUTING.md README.md \
		TEMPLATES.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
