PORTNAME=	glab
DISTVERSIONPREFIX=	v
DISTVERSION=	1.22.0
CATEGORIES=	devel

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Open-source GitLab command line tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules

_BUILD_VERSION=	${DISTVERSION}
_BUILD_DATE=	$$(date +%d/%m/%Y)

GO_MODULE=	github.com/profclems/${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags "\
		-s -w \
		-X main.version=${_BUILD_VERSION} \
		-X main.build=${_BUILD_DATE}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md SECURITY.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
