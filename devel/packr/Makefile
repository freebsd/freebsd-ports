# $FreeBSD$

PORTNAME=	packr
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.1
CATEGORIES=	devel

MAINTAINER=	dg@syrec.org
COMMENT=	Simple and easy way to embed static files into Go binaries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	gobuffalo
GH_SUBDIR=	src/github.com/gobuffalo/packr
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:toml/src/github.com/BurntSushi/toml \
		gobuffalo:buffalo-plugins:v1.11.0:buffalo_plugins/src/github.com/gobuffalo/buffalo-plugins \
		gobuffalo:envy:v1.6.12:envy/src/github.com/gobuffalo/envy \
		gobuffalo:events:v1.1.9:events/src/github.com/gobuffalo/events \
		gobuffalo:flect:a62e61d:flect/src/github.com/gobuffalo/flect \
		gobuffalo:genny:f31a84f:genny/src/github.com/gobuffalo/genny \
		gobuffalo:logger:5b956e2:logger/src/github.com/gobuffalo/logger \
		gobuffalo:mapi:v1.0.1:mapi/src/github.com/gobuffalo/mapi \
		gobuffalo:meta:50bbb1f:meta/src/github.com/gobuffalo/meta \
		gobuffalo:packd:eca3b8f:packd/src/github.com/gobuffalo/packd \
		gobuffalo:syncx:558ac7d:syncx/src/github.com/gobuffalo/syncx \
		golang:crypto:ff983b9:crypto/src/golang.org/x/crypto \
		golang:sync:37e7f08:sync/src/golang.org/x/sync \
		golang:sys:11f53e0:sys/src/golang.org/x/sys \
		golang:tools:16909d2:tools/src/golang.org/x/tools \
		inconshreveable:mousetrap:v1.0.0:mousetrap/src/github.com/inconshreveable/mousetrap \
		joho:godotenv:v1.3.0:godotenv/src/github.com/joho/godotenv \
		karrick:godirwalk:v1.7.8:godirwalk/src/github.com/karrick/godirwalk \
		markbates:oncer:bf2de49:oncer/src/github.com/markbates/oncer \
		markbates:safe:v1.0.1:safe/src/github.com/markbates/safe \
		pkg:errors:v0.8.1:pkg/src/github.com/pkg/errors \
		rogpeppe:go-internal:v1.1.0:go_internal/src/github.com/rogpeppe/go-internal \
		sirupsen:logrus:v1.3.0:logrus/src/github.com/sirupsen/logrus \
		spf13:cobra:v0.0.3:cobra/src/github.com/spf13/cobra \
		spf13:pflag:v1.0.3:pflag/src/github.com/spf13/pflag

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
