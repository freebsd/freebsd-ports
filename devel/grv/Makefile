# $FreeBSD$

PORTNAME=	grv
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.2
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
		camlistore:go4:fba789b:reflectutil/src/go4.org \
		gobwas:glob:51eb1ee:glob/src/github.com/gobwas/glob \
		golang:crypto:1875d0a:crypto/src/golang.org/x/crypto \
		golang:sys:37707fd:sys/src/golang.org/x/sys \
		mattn:go-runewidth:97311d9:runewidth/src/github.com/mattn/go-runewidth \
		rgburke:goncurses:74f667a:goncurses/src/github.com/rgburke/goncurses \
		rjeczalik:notify:c31e5f2:notify/src/github.com/rjeczalik/notify \
		Sirupsen:logrus:768a92a:logrus/src/github.com/Sirupsen/logrus \
		tchap:go-patricia:5ad6cdb:patricia/src/github.com/tchap/go-patricia \
		libgit2:git2go:eb0bf21:git2go/src/gopkg.in/libgit2/git2go.v26 # Keep git2go branch in sync with devel/libgit2 version

PLIST_FILES=	bin/grv

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-build:
	@cd ${WRKSRC} && ${SETENV} GOPATH=${WRKSRC} go build ./cmd/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
