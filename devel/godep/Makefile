# $FreeBSD$

PORTNAME=	godep
PORTVERSION=	69
CATEGORIES=	devel
DISTVERSIONPREFIX=	v

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Godep helps build packages reproducibly

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	tools

PLIST_FILES=	bin/godep

STRIP=		# stripping can break go binaries

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.for src in *.go .gitignore .travis.yml Changelog.md Godeps License Readme.md
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/tools/${PORTNAME}
.endfor

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; ${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
