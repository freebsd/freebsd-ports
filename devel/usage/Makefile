PORTNAME=	usage
DISTVERSIONPREFIX=	v
DISTVERSION=	6.12.0
CATEGORIES=	devel

MAINTAINER=	jkh@FreeBSD.org
COMMENT=	Specification and toolkit for CLI argument parsing and completions
WWW=		https://usage.jdx.dev/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	jdx

CARGO_INSTALL_PATH=	cli

PLIST_FILES=	bin/${PORTNAME} \
		share/bash-completion/completions/${PORTNAME} \
		share/fish/vendor_completions.d/${PORTNAME}.fish \
		share/man/man1/${PORTNAME}.1.gz \
		share/zsh/site-functions/_${PORTNAME}

post-install:
	${INSTALL_MAN} ${WRKSRC}/cli/assets/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/cli/assets/completions/${PORTNAME}.bash \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/cli/assets/completions/${PORTNAME}.fish \
		${STAGEDIR}${PREFIX}/share/fish/vendor_completions.d
	${INSTALL_DATA} ${WRKSRC}/cli/assets/completions/_${PORTNAME} \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

.include <bsd.port.mk>
