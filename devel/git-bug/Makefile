PORTNAME=	git-bug
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
PORTREVISION=	17
CATEGORIES=	devel

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Distributed, offline-first bug tracker embedded in git, with bridges
WWW=		https://github.com/MichaelMure/git-bug

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules

_BUILD_COMMIT=	a3fa445

GO_MODULE=	github.com/MichaelMure/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
	       -s -w \
	       -X ${GO_MODULE}/commands.GitCommit=${_BUILD_COMMIT} \
	       -X ${GO_MODULE}/commands.GitLastTag=${DISTVERSION} \
	       -X ${GO_MODULE}/commands.GitExactTag=${DISTVERSION}"

OPTIONS_DEFINE=		COMPLETIONS MANPAGES
OPTIONS_DEFAULT=	COMPLETIONS MANPAGES
OPTIONS_SUB=		yes

COMPLETIONS_DESC=		Build and install bash, fish and zsh shell completions
COMPLETIONS_PLIST_FILES=	share/bash-completion/completions/${PORTNAME} \
				share/fish/vendor_completions.d/${PORTNAME}.fish \
				share/zsh/site-functions/_${PORTNAME}

post-install-COMPLETIONS-on:
.for _shell in bash fish zsh
	${GO_WRKDIR_BIN}/${PORTNAME} completion ${_shell} \
		>${STAGEDIR}${PREFIX}/${COMPLETIONS_PLIST_FILES:M*${_shell}*}
.endfor

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
