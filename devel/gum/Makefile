PORTNAME=	gum
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	devel

MAINTAINER=	dave@bitboss.ca
COMMENT=	Tool for glamorous shell scripts
WWW=		https://github.com/charmbracelet/gum

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/charmbracelet/gum

PLIST_FILES=	bin/gum \
		etc/bash_completion.d/gum \
		man/man1/gum.1.gz \
		share/zsh/site-functions/_gum

post-build:
	${MKDIR} ${WRKDIR}/manpages
	${WRKDIR}/bin/gum man > ${WRKDIR}/manpages/gum.1

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/bin/gum ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKDIR}/manpages/gum.1 ${STAGEDIR}${PREFIX}/man/man1/
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${WRKDIR}/bin/gum completion bash > ${STAGEDIR}${PREFIX}/etc/bash_completion.d/gum
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${WRKDIR}/bin/gum completion zsh > ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_gum

.include <bsd.port.mk>
