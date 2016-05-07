# Created by: Simon Olofsson <simon@olofsson.de>
# $FreeBSD$

PORTNAME=	hub
PORTVERSION=	2.2.3
DISTVERSIONPREFIX=v
CATEGORIES=	devel

MAINTAINER=	koukopoulos@gmail.com
COMMENT=	Introduces git to GitHub

LICENSE=	MIT

BUILD_DEPENDS=	go:lang/go \
		bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	github

STRIP=		# stripping can break go binaries

PLIST_FILES=	bin/hub \
		etc/bash_completion.d/hub \
		share/zsh/site-functions/_hub \
		man/man1/hub.1.gz
do-build:
	@cd ${WRKSRC} ; ${SETENV} ${LOCALBASE}/bin/bash script/build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hub ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/hub.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/etc/hub.bash_completion.sh ${STAGEDIR}${PREFIX}/etc/bash_completion.d/hub
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/etc/hub.zsh_completion ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_hub

.include <bsd.port.mk>
