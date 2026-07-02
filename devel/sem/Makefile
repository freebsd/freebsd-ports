PORTNAME=	sem
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.1
CATEGORIES=	devel

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Semantic version control for git
WWW=		https://ataraxy-labs.github.io/sem/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	ataraxy-labs

CARGO_CARGOTOML=	${WRKSRC}/crates/sem-cli/Cargo.toml
CARGO_INSTALL_PATH=	./crates/sem-cli
# For maintainer:
CARGO_LOCK_URL=	https://raw.githubusercontent.com/ataraxy-labs/sem/refs/tags/${DISTVERSIONPREFIX}${DISTVERSION}/crates/Cargo.lock

PLIST_FILES=	bin/sem \
		share/bash-completion/completions/sem.bash \
		share/fish/vendor_completions.d/sem.fish \
		share/zsh/site-functions/_sem
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${STAGEDIR}${PREFIX}/bin/sem completions bash \
		> ${STAGEDIR}${PREFIX}/share/bash-completion/completions/sem.bash
	${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d
	${STAGEDIR}${PREFIX}/bin/sem completions fish \
		> ${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d/sem.fish
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${STAGEDIR}${PREFIX}/bin/sem completions zsh \
		> ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_sem

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/docs/*.html \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
