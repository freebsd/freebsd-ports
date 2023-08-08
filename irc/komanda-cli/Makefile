PORTNAME=	komanda-cli
DISTVERSION=	g20190920
PORTREVISION=	13
CATEGORIES=	irc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Komanda command-line IRC client
WWW=		https://github.com/mephux/komanda-cli

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	mephux
GH_TAGNAME=	b5ba03b
GH_TUPLE=	golang:sys:v0.6.0:sys

DEPRECATED=	Upstream no longer maintained
EXPIRATION_DATE=	2023-08-25

_BUILD_SHA=	${GH_TAGNAME}
_BUILD_COUNT=	138
_BUILD_TAG=	${_BUILD_COUNT}.${_BUILD_SHA}

GO_BUILDFLAGS=	-ldflags "\
		${STRIP} -w \
		-X main.Build=${_BUILD_TAG}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
