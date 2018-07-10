# $FreeBSD$

PORTNAME=	grv
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
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
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}
GH_TUPLE=	bradfitz:slice:d9036e2:slice/src/github.com/bradfitz/slice \
		camlistore:go4:9599cf2:reflectutil/src/go4.org \
		davecgh:go-spew:8991bc2:spew/src/github.com/davecgh/go-spew \
		gobwas:glob:f00a739:glob/src/github.com/gobwas/glob \
		golang:crypto:a49355c:crypto/src/golang.org/x/crypto \
		golang:sys:63fc586:sys/src/golang.org/x/sys \
		mattn:go-runewidth:ce7b0b5:runewidth/src/github.com/mattn/go-runewidth \
		pmezard:go-difflib:792786c:difflib/src/github.com/pmezard/go-difflib \
		rgburke:goncurses:74f667a:goncurses/src/github.com/rgburke/goncurses \
		rjeczalik:notify:d152f3c:notify/src/github.com/rjeczalik/notify \
		Sirupsen:logrus:75068be:logrus/src/github.com/Sirupsen/logrus \
		stretchr:objx:0ab728f:objx/src/github.com/stretchr/objx \
		stretchr:testify:f35b8ab:testify/src/github.com/stretchr/testify \
		tchap:go-patricia:5ad6cdb:patricia/src/github.com/tchap/go-patricia \
		libgit2:git2go:9abc050:git2go/src/gopkg.in/libgit2/git2go.v27 # Keep git2go branch in sync with devel/libgit2 version

PLIST_FILES=	bin/grv

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build ./cmd/${PORTNAME}

do-test:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go test ./cmd/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
