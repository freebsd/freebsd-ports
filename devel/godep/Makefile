# $FreeBSD$

PORTNAME=	godep
PORTVERSION=	0.0.0.2015061101
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Godep helps build packages reproducibly

BUILD_DEPENDS=	${LOCALBASE}/bin/go:${PORTSDIR}/lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	tools:DEFAULT kr:fs golang:tools
GH_PROJECT=	godep:DEFAULT fs:fs tools:tools
GH_TAGNAME=	e28aafa:DEFAULT 2788f0d:fs a6d2a42:tools

PLIST_FILES=	bin/godep

STRIP=		# stripping can break go binaries

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.for src in .gitignore License Readme.md dep.go doc.go get.go go.go main.go \
	match_test.go path.go pkg.go restore.go rewrite.go rewrite_test.go \
	save.go save_test.go update.go update_test.go util.go vcs.go
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/tools/${PORTNAME}
.endfor
	@${MKDIR} ${WRKSRC}/src/github.com/kr
	@${MKDIR} ${WRKSRC}/src/golang.org/x
	@${MV} ${WRKSRC_fs} ${WRKSRC}/src/github.com/kr/fs
	@${MV} ${WRKSRC_tools} ${WRKSRC}/src/golang.org/x/tools

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; ${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
