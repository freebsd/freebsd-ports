# Created by: Simon Olofsson <simon@olofsson.de>
# $FreeBSD$

PORTNAME=	hub
PORTVERSION=	2.12.8
DISTVERSIONPREFIX=	v
CATEGORIES=	devel sysutils

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Introduces git to GitHub

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	github

GO_PKGNAME=	github.com/github/hub

PLIST_FILES=	bin/hub \
		etc/bash_completion.d/hub \
		man/man1/hub.1.gz \
		share/fish/completions/hub.fish \
		share/zsh/site-functions/_hub

OPTIONS_DEFINE=		GIT_SUBVERSION

GIT_SUBVERSION_DESC=	Use 'git-subversion' instead of 'git' as backend

GIT_SUBVERSION_RUN_DEPENDS=	git-subversion>0:devel/git-subversion
GIT_SUBVERSION_RUN_DEPENDS_OFF=	git:devel/git

post-build:
	(cd ${GO_WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} install ${GO_BUILDFLAGS} ${GO_TARGET}/md2roff-bin)
	(cd ${GO_WRKSRC} && \
	  ${WRKDIR}/bin/md2roff-bin --manual="hub" --version="${PORTVERSION}" \
	  --template=${GO_WRKSRC}/man-template.html share/man/man1/*.md)

post-install:
	${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1 \
	  ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
	  ${STAGEDIR}${PREFIX}/share/fish/completions \
	  ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/etc/hub.bash_completion.sh ${STAGEDIR}${PREFIX}/etc/bash_completion.d/hub
	${INSTALL_DATA} ${WRKSRC}/etc/hub.fish_completion ${STAGEDIR}${PREFIX}/share/fish/completions/hub.fish
	${INSTALL_DATA} ${WRKSRC}/etc/hub.zsh_completion ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_hub
	${INSTALL_MAN} ${WRKSRC}/share/man/man1/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
