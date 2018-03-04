# $FreeBSD$

PORTNAME=	go-bindata
PORTVERSION=	3.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Generates Go code from any file

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	jteeuwen
GH_TAGNAME=	a0ff256
GH_SUBDIR=	src/github.com/jteeuwen/go-bindata

PLIST_FILES=	bin/go-bindata

PORTDOCS=	CONTRIBUTING.md LICENSE README.md

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC} ; \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build -o bin/go-bindata ./go-bindata/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}

do-install-DOCS-on:
.for x in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/${x} \
		${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
