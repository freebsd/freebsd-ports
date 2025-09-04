PORTNAME=	doggo
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.5
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES=	dns

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern command-line DNS client (like dig)
WWW=		https://github.com/mr-karan/doggo

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=	default webui
FLAVOR?=	${FLAVORS:[1]}
webui_PKGNAMESUFFIX=	-webui

USES=		go:modules

.if ${FLAVOR} == webui
COMMENT+=	(web UI version)
.endif

GO_MODULE=	github.com/mr-karan/doggo
.if ${FLAVOR} == default
GO_TARGET=	./cmd/${PORTNAME}
.endif
.if ${FLAVOR} == webui
GO_TARGET=	./web
.endif

.if ${FLAVOR} == default
PLIST_FILES=	bin/${PORTNAME} \
		share/bash-completion/completions/_${PORTNAME} \
		share/fish/completions/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}
.endif
.if ${FLAVOR} == webui
PLIST_FILES=	bin/${PORTNAME}-webui
.endif

.if ${FLAVOR} == default
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
.endif

.if ${FLAVOR} == webui
post-install: # rename executable
	@${MV} ${STAGEDIR}${PREFIX}/bin/web ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-webui
.endif

.include <bsd.port.mk>
