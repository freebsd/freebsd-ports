# Created by: Simon Olofsson <simon@olofsson.de>
# $FreeBSD$

PORTNAME=	hub
PORTVERSION=	2.6.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel sysutils

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Introduces git to GitHub

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ronn:textproc/rubygem-ronn
RUN_DEPENDS=	git:devel/git

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	github

GO_PKGNAME=	github.com/github/hub

PLIST_FILES=	bin/hub	\
		man/man1/hub.1.gz

OPTIONS_DEFINE=		BASH FISH ZSH

BASH_PLIST_FILES=	etc/bash_completion.d/hub
BASH_RUN_REPENDS=	bash:shells/bash
FISH_PLIST_FILES=	share/fish/completions/hub.fish
FISH_RUN_REPENDS=	fish:shells/fish
ZSH_PLIST_FILES=	share/zsh/site-functions/_hub
ZSH_RUN_REPENDS=	zsh:shells/zsh

post-build:
	${MKDIR} ${STAGEDIR}${MAN1PREFIX}/man/man1
	cd ${WRKSRC}/share/man/man1 && \
		${LOCALBASE}/bin/ronn -r hub.1.ronn
	${INSTALL_MAN} ${WRKSRC}/share/man/man1/hub.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

post-install-BASH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/etc/hub.bash_completion.sh ${STAGEDIR}${PREFIX}/etc/bash_completion.d/hub

post-install-FISH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/etc/hub.fish_completion ${STAGEDIR}${PREFIX}/share/fish/completions/hub.fish

post-install-ZSH-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/etc/hub.zsh_completion ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_hub

.include <bsd.port.mk>
