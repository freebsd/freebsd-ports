# $FreeBSD$

PORTNAME=	godep
PORTVERSION=	0.0.0.2015080301
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Godep helps build packages reproducibly

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	tools
GH_TAGNAME=	d8799f1

PLIST_FILES=	bin/godep

STRIP=		# stripping can break go binaries

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.for src in .gitignore .travis.yml Godeps License Readme.md dep.go diff.go \
	diff_test.go doc.go get.go go.go main.go match_test.go path.go pkg.go \
	restore.go rewrite.go rewrite_test.go save.go save_test.go update.go \
	update_test.go util.go vcs.go
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/tools/${PORTNAME}
.endfor

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; ${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
