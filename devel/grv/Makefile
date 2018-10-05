# $FreeBSD$

PORTNAME=	grv
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
CATEGORIES=	devel

MAINTAINER=	dg@syrec.org
COMMENT=	Terminal interface for viewing git repositories

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go
LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		ncurses pkgconfig readline:port
USE_GITHUB=	yes
GH_ACCOUNT=	rgburke
GH_SUBDIR=	src/github.com/rgburke/grv
GH_TUPLE=	bradfitz:slice:2b758aa:slice/src/github.com/bradfitz/slice \
		camlistore:go4:417644f:reflectutil/src/go4.org \
		davecgh:go-spew:d8f796a:spew/src/github.com/davecgh/go-spew \
		gobwas:glob:f756513:glob/src/github.com/gobwas/glob \
		golang:crypto:5295e83:crypto/src/golang.org/x/crypto \
		golang:sys:e4b3c5e:sys/src/golang.org/x/sys \
		mattn:go-runewidth:ce7b0b5:runewidth/src/github.com/mattn/go-runewidth \
		pmezard:go-difflib:792786c:difflib/src/github.com/pmezard/go-difflib \
		rgburke:goncurses:74f667a:goncurses/src/github.com/rgburke/goncurses \
		rjeczalik:notify:69d839f:notify/src/github.com/rjeczalik/notify \
		Sirupsen:logrus:a67f783:logrus/src/github.com/Sirupsen/logrus \
		stretchr:objx:ef50b0d:objx/src/github.com/stretchr/objx \
		stretchr:testify:f35b8ab:testify/src/github.com/stretchr/testify \
		tchap:go-patricia:5ad6cdb:patricia/src/github.com/tchap/go-patricia \
		libgit2:git2go:c0c2948:git2go/src/gopkg.in/libgit2/git2go.v27 # Keep git2go branch in sync with devel/libgit2 version

PLIST_FILES=	bin/grv

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build ./cmd/${PORTNAME}

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go test ./cmd/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
