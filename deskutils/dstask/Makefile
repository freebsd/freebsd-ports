# $FreeBSD$

PORTNAME=	dstask
DISTVERSIONPREFIX=	v
DISTVERSION=	0.23
CATEGORIES=	deskutils

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Single binary terminal-based TODO manager with git-based sync

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules
GO_TARGET=	./cmd/dstask.go

USE_GITHUB=	yes
GH_ACCOUNT=	naggie

PLIST_FILES=	bin/${PORTNAME} \
		${DOCSDIR_REL}/README.md \
		etc/bash_completion.d/${PORTNAME}.sh \
		share/zsh/site-functions/_${PORTNAME}

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}.go \
		 ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/.${PORTNAME}-zsh-completions.sh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/.${PORTNAME}-bash-completions.sh \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}.sh

.include <bsd.port.mk>
