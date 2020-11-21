# $FreeBSD$

PORTNAME=	dstask
DISTVERSIONPREFIX=	v
DISTVERSION=	0.23.2
CATEGORIES=	deskutils

# Temporary patch to fix a build issue in released version
PATCHFILES=	947deb069256bcec020756ce052ccc718e68cfb5.diff:-p1
PATCH_SITES=	https://github.com/naggie/dstask/commit/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Single binary terminal-based TODO manager with git-based sync

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules
GO_TARGET=	cmd/dstask/main.go

USE_GITHUB=	yes
GH_ACCOUNT=	naggie

PLIST_FILES=	bin/${PORTNAME} \
		${DOCSDIR_REL}/README.md \
		etc/bash_completion.d/${PORTNAME}.sh \
		share/zsh/site-functions/_${PORTNAME}

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/${GO_TARGET:T} \
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
