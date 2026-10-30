PORTNAME=	forgejo-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
CATEGORIES=	devel

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	CLI client for Forgejo

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo ssl
USE_FORGEJO=	yes
FJ_ACCOUNT=	forgejo-contrib

PLIST_FILES=	bin/fj \
		share/bash-completion/completions/fj \
		share/fish/completions/fj.fish \
		share/zsh/site-functions/_fj

post-install:
	${MKDIR} \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions \
		${STAGEDIR}${PREFIX}/share/fish/completions \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${CARGO_TARGET_DIR}/release/fj completion bash > \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/fj
	${CARGO_TARGET_DIR}/release/fj completion fish > \
		${STAGEDIR}${PREFIX}/share/fish/completions/fj.fish
	${CARGO_TARGET_DIR}/release/fj completion zsh > \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_fj

.include <bsd.port.mk>
