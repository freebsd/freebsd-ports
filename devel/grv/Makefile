# $FreeBSD$

PORTNAME=	grv
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.2
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Terminal interface for viewing git repositories

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		go ncurses pkgconfig readline:port
USE_GITHUB=	yes
GH_ACCOUNT=	rgburke
GH_SUBDIR=	src/github.com/rgburke/grv
GH_TUPLE=	bradfitz:slice:2b758aa:slice/vendor/github.com/bradfitz/slice \
		camlistore:go4:94abd69:reflectutil/vendor/go4.org \
		davecgh:go-spew:d8f796a:spew/vendor/github.com/davecgh/go-spew \
		gobwas:glob:e7a84e9:glob/vendor/github.com/gobwas/glob \
		golang:crypto:a1f597e:crypto/vendor/golang.org/x/crypto \
		golang:sys:fead790:sys/vendor/golang.org/x/sys \
		mattn:go-runewidth:703b5e6:runewidth/vendor/github.com/mattn/go-runewidth \
		pmezard:go-difflib:5d4384e:difflib/vendor/github.com/pmezard/go-difflib \
		rgburke:goncurses:74f667a:goncurses/vendor/github.com/rgburke/goncurses \
		rjeczalik:notify:629144b:notify/vendor/github.com/rjeczalik/notify \
		Sirupsen:logrus:v1.4.0:logrus/vendor/github.com/Sirupsen/logrus \
		stretchr:objx:c61a9df:objx/vendor/github.com/stretchr/objx \
		stretchr:testify:34c6fa2:testify/vendor/github.com/stretchr/testify \
		tchap:go-patricia:v2.3.0:patricia/vendor/github.com/tchap/go-patricia \
		libgit2:git2go:ecaeb7a:git2go/vendor/gopkg.in/libgit2/git2go.v27 # Keep this in sync with devel/libgit2 version

GO_TARGET=	./cmd/grv
GO_BUILDFLAGS=	-ldflags "-X main.version=${PORTVERSION}"

PLIST_FILES=	bin/grv

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-test:
	cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} test ${GO_BUILDLAGS} ${GO_TARGET}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
