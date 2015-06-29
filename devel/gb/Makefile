# $FreeBSD$

PORTNAME=	gb
PORTVERSION=	0.0.0.2015062801
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Project based build tool for Go

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	constabulary
GH_TAGNAME=	d14e213

PLIST_FILES=	bin/gb bin/gb-vendor

PORTDOCS=	README.md LICENSE

STRIP=		# stripping can break go binaries

.include <bsd.port.options.mk>

post-extract:
	@cd ${WRKSRC} ; ${MKDIR} src/github.com/${GH_ACCOUNT}/${GH_PROJECT} ; \
		${MV} .gitignore LICENSE README.md build.go build_test.go \
		cgo.go cgo14.go cgo15.go cmd context.go context_test.go \
		defaultcc.go defaultcc_bsd.go gb.go gb_test.go gc.go gc14.go \
		gc15.go install.go log.go package.go package_test.go project.go \
		src.go stdlib.go target.go testdata wercker.yml \
		src/github.com/${GH_ACCOUNT}/${GH_PROJECT}

do-build:
	@cd ${WRKSRC} ; \
		${SETENV} GOPATH=${WRKSRC} go install ./...

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gb \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/gb-vendor \
		${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/README.md \
		${STAGEDIR}${DOCSDIR}
	${CP} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/LICENSE \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
