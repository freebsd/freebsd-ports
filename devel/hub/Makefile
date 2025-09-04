PORTNAME=	hub
PORTVERSION=	2.14.2
DISTVERSIONPREFIX=	v
PORTREVISION=	31
CATEGORIES=	devel sysutils

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Introduces git to GitHub
WWW=		https://hub.github.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		cpe go:modules
CPE_VENDOR=	${PORTNAME}_project

USE_GITHUB=	yes
GH_ACCOUNT=	github
GH_TUPLE=	golang:sys:v0.6.0:sys

GO_PKGNAME=	github.com/github/hub

PLIST_FILES=	bin/hub \
		etc/bash_completion.d/hub \
		share/man/man1/hub.1.gz \
		share/fish/completions/hub.fish \
		share/zsh/site-functions/_hub

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

post-build:
	(cd ${GO_WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} install ${GO_BUILDFLAGS} ${GO_TARGET}/md2roff-bin)
	(cd ${GO_WRKSRC} && \
	  ${WRKDIR}/bin/md2roff-bin --manual="hub" --version="${PORTVERSION}" \
	  --template=${GO_WRKSRC}/man-template.html share/man/man1/*.md)

post-install:
	${MKDIR} \
	  ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
	  ${STAGEDIR}${PREFIX}/share/fish/completions \
	  ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/etc/hub.bash_completion.sh ${STAGEDIR}${PREFIX}/etc/bash_completion.d/hub
	${INSTALL_DATA} ${WRKSRC}/etc/hub.fish_completion ${STAGEDIR}${PREFIX}/share/fish/completions/hub.fish
	${INSTALL_DATA} ${WRKSRC}/etc/hub.zsh_completion ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_hub
	${INSTALL_MAN} ${WRKSRC}/share/man/man1/*.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
