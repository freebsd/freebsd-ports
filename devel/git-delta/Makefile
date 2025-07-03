PORTNAME=	delta
DISTVERSION=	0.18.2
PORTREVISION=	7
CATEGORIES=	devel
PKGNAMEPREFIX=	git-

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Syntax-highlighting pager for git/diff
WWW=		https://dandavison.github.io/delta/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libonig.so:devel/oniguruma
RUN_DEPENDS=	git:devel/git

USES=		cargo cpe
CPE_VENDOR=	${PORTNAME}_project
USE_GITHUB=	yes
GH_ACCOUNT=	dandavison

TEST_TARGET=	test

CONFLICTS_INSTALL=	delta
PLIST_FILES=		bin/delta

OPTIONS_DEFINE=		BASH FISH ZSH
OPTIONS_DEFAULT=	BASH FISH ZSH
BASH_PLIST_FILES=	etc/bash_completion.d/_${PORTNAME}.bash
FISH_PLIST_FILES=	share/fish/vendor_functions.d/${PORTNAME}.fish
ZSH_PLIST_FILES=	share/zsh/site-functions/_${PORTNAME}

post-install-BASH-on:
	${MKDIR} ${STAGEDIR}${LOCALBASE}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/etc/completion/completion.bash \
			${STAGEDIR}${PREFIX}/etc/bash_completion.d/_${PORTNAME}.bash

post-install-FISH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/vendor_functions.d
	${INSTALL_DATA} ${WRKSRC}/etc/completion/completion.fish \
			${STAGEDIR}${PREFIX}/share/fish/vendor_functions.d/${PORTNAME}.fish

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/etc/completion/completion.zsh \
			${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
