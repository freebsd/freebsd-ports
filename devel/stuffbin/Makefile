PORTNAME=	stuffbin
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
PORTREVISION=	14
CATEGORIES=	devel

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Compress and embed static files and assets into Go binaries
WWW=		https://github.com/knadh/stuffbin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/knadh/${PORTNAME}
GO_TARGET=	./${PORTNAME}:${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
