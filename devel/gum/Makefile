PORTNAME=	gum
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.0
CATEGORIES=	devel

MAINTAINER=	dave@bitboss.ca
COMMENT=	Tool for glamorous shell scripts
WWW=		https://github.com/charmbracelet/gum

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/charmbracelet/gum

PLIST_FILES=	bin/gum \
		etc/bash_completion.d/gum.bash \
		share/fish/completions/gum.fish \
		share/man/man1/gum.1.gz \
		share/zsh/site-functions/_gum

post-build:
	${GO_WRKDIR_BIN}/${PORTNAME} man > ${WRKSRC}/${PORTNAME}.1
.for SHELL in bash fish zsh
	${GO_WRKDIR_BIN}/${PORTNAME} completion ${SHELL} > ${WRKSRC}/${SHELL}
.endfor

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		 ${STAGEDIR}${PREFIX}/share/fish/completions \
		 ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}.bash
	${INSTALL_DATA} ${WRKSRC}/fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish
	${INSTALL_DATA} ${WRKSRC}/zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
