PORTNAME=	doggo
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.4
PORTEPOCH=	1
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern command-line DNS client (like dig)
WWW=		https://github.com/mr-karan/doggo

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/mr-karan/doggo
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/bash-completion/completions/_${PORTNAME} \
		share/fish/completions/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

post-install: # install completions
	# bash
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} completions bash > \
		${STAGEDIR}${PREFIX}/share/bash-completion/completions/_${PORTNAME}
	# fish
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/fish/completions
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} completions fish > \
		${STAGEDIR}${PREFIX}/share/fish/completions/${PORTNAME}.fish
	# zsh
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} completions zsh > \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_${PORTNAME}

.include <bsd.port.mk>
