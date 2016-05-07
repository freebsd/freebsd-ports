# $FreeBSD$

PORTNAME=	go-bindata
PORTVERSION=	3.0.7
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Generates Go code from any file

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	jteeuwen

PLIST_FILES=	bin/go-bindata

PORTDOCS=	CONTRIBUTING.md LICENSE README.md

STRIP=		# stripping can break go binaries

OPTIONS_DEFINE=	DOCS

post-patch:
	@cd ${WRKSRC} ; ${MKDIR} src/github.com/${GH_ACCOUNT}/${GH_PROJECT} ; \
	${MV} CONTRIBUTING.md LICENSE README.md asset.go bytewriter.go \
	config.go convert.go debug.go doc.go go-bindata release.go \
	stringwriter.go testdata toc.go \
	src/github.com/${GH_ACCOUNT}/${GH_PROJECT}

do-build:
	cd ${WRKSRC} ; \
		${SETENV} GOPATH=${WRKSRC} go install ./...

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
