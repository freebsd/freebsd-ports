# $FreeBSD$

PORTNAME=	gb
PORTVERSION=	0.0.0.2015050101
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Project based build tool for Go

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	constabulary
GH_TAGNAME=	400dce5e5172bcbaf609e6a1107988bb5571dc90

PLIST_FILES=	bin/gb bin/gb-env bin/gb-vendor

PORTDOCS=	README.md

STRIP=		# stripping can break go binaries

.include <bsd.port.options.mk>

post-patch:
	@cd ${WRKSRC} ; ${MKDIR} src/github.com/${GH_ACCOUNT}/${GH_PROJECT} ; \
		${CP} -R LICENSE README.md build.go build_test.go cgo.go cmd \
		context.go gb.go gc.go getting-started.md gotest_go11.go \
		install.go log.go package.go package_test.go project.go \
		stdlib.go target.go test.go test_test.go testdata toolchain.go \
		util.go wercker.yml \
		src/github.com/${GH_ACCOUNT}/${GH_PROJECT}

do-build:
	cd ${WRKSRC} ; \
		${SETENV} GOPATH=${WRKSRC} go build -o gb-env \
		src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/cmd/gb-env/main.go ; \
		${SETENV} GOPATH=${WRKSRC} go build -o gb \
		src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/cmd/gb/main.go \
		src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/cmd/gb/plugin.go  \
		src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/cmd/gb/build.go \
		src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/cmd/gb/test.go ; \
		${SETENV} GOPATH=${WRKSRC} go build -o gb-vendor \
		src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/cmd/gb-vendor/main.go

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gb \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/gb-env \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/gb-vendor \
		${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/README.md \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
