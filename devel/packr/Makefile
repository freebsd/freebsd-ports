# $FreeBSD$

PORTNAME=	packr
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.5
CATEGORIES=	devel

MAINTAINER=	dg@syrec.org
COMMENT=	Simple and easy way to embed static files into Go binaries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	gobuffalo
GH_SUBDIR=	src/github.com/gobuffalo/packr
GH_TUPLE=	golang:net:c394268:net/src/golang.org/x/net \
		golang:sync:1d60e46:sync/src/golang.org/x/sync \
		pkg:errors:v0.8.0:errors/src/github.com/pkg/errors \
		spf13:cobra:v0.0.3:cobra/src/github.com/spf13/cobra \
		spf13:pflag:v1.0.2:pflag/src/github.com/spf13/pflag

PLIST_FILES=	bin/packr

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-build:
	cd ${WRKSRC}/${GH_SUBDIR}/packr && ${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${GH_SUBDIR}/packr/packr ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
