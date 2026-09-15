PORTNAME=	zizmor
DISTVERSIONPREFIX=	v
DISTVERSION=	1.30.1
CATEGORIES=	devel

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Static analysis for GitHub Actions
WWW=		https://docs.zizmor.sh/ \
		https://github.com/zizmorcore/zizmor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	zizmorcore

CARGO_INSTALL_PATH=	crates/zizmor

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CONTRIBUTING.md README.md

OPTIONS_DEFINE=	COMPLETIONS DOCS
OPTIONS_DEFAULT=COMPLETIONS

COMPLETIONS_DESC=	Build and/or install shell completions

COMPLETIONS_PLIST_FILES=etc/bash_completion.d/${PORTNAME} \
			share/fish/completions/${PORTNAME}.fish \
			share/zsh/site-functions/_${PORTNAME}

post-build-COMPLETIONS-on:
.for shell in bash fish zsh
	${CARGO_TARGET_DIR}/*/${PORTNAME} --completions ${shell} > \
		${WRKSRC}/${PORTNAME}.${shell}
.endfor

post-install-COMPLETIONS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		${STAGEDIR}${PREFIX}/share/fish/completions \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
