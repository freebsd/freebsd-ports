PORTNAME=	dstask
DISTVERSIONPREFIX=	v
DISTVERSION=	0.26
PORTREVISION=	23
CATEGORIES=	deskutils

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Single binary terminal-based TODO manager with git-based sync
WWW=		https://github.com/naggie/dstask

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules
GO_TARGET=	./cmd/dstask ./cmd/dstask-import

USE_GITHUB=	yes
GH_ACCOUNT=	naggie
GH_TUPLE=	golang:sys:v0.6.0:sys

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}/${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/.${PORTNAME}-zsh-completions.sh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/.${PORTNAME}-bash-completions.sh \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/${PORTNAME}.sh

.include <bsd.port.mk>
