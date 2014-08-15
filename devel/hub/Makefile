# Created by: Simon Olofsson <simon@olofsson.de>
# $FreeBSD$

PORTNAME=	hub
PORTVERSION=	1.12.2
CATEGORIES=	devel

MAINTAINER=	koukopoulos@gmail.com
COMMENT=	Introduces git to GitHub

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	github
GH_TAGNAME=	v${DISTVERSION}
GH_COMMIT=	9016a39

USE_RUBY=	yes
USE_RAKE=	yes

PLIST_FILES=	bin/hub \
		etc/bash_completion.d/hub \
		share/zsh/site-functions/_hub \
		man/man1/hub.1.gz
PLIST_DIRSTRY=	etc/bash_completion.d \
		share/zsh/site-functions share/zsh

do-build:
	@cd ${WRKSRC} && ${RAKE_BIN} standalone

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/hub ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/hub.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/etc/hub.bash_completion.sh ${STAGEDIR}${PREFIX}/etc/bash_completion.d/hub
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/etc/hub.zsh_completion ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_hub

.include <bsd.port.mk>
