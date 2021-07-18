PORTNAME=	git-bug
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Distributed, offline-first bug tracker embedded in git, with bridges

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules

_BUILD_COMMIT=	cc4a93c8ce931b1390c61035b888ad17110b7bd6

GO_MODULE=	github.com/MichaelMure/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
	       -s -w \
	       -X ${GO_MODULE}/commands.GitCommit=${_BUILD_COMMIT} \
	       -X ${GO_MODULE}/commands.GitLastTag=${DISTVERSION} \
	       -X ${GO_MODULE}/commands.GitExactTag=${DISTVERSION}"

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/*.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1

	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions

	${INSTALL_DATA} ${WRKSRC}/misc/bash_completion/${PORTNAME} \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/misc/zsh_completion/${PORTNAME} \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
