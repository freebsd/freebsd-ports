# $FreeBSD$

PORTNAME=	packr
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0
CATEGORIES=	devel

MAINTAINER=	dg@syrec.org
COMMENT=	Simple and easy way to embed static files into Go binaries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules

GO_PKGNAME=	github.com/gobuffalo/packr
GO_TARGET=	./packr \
		./v2/packr2

USE_GITHUB=	yes
GH_ACCOUNT=	gobuffalo
GH_TUPLE=	\
		gobuffalo:envy:v1.7.0:gobuffalo_envy/vendor/github.com/gobuffalo/envy \
		gobuffalo:genny:3ca520ef0d9e:gobuffalo_genny/vendor/github.com/gobuffalo/genny \
		gobuffalo:gogen:8f38393713f5:gobuffalo_gogen/vendor/github.com/gobuffalo/gogen \
		gobuffalo:logger:86e12af44bc2:gobuffalo_logger/vendor/github.com/gobuffalo/logger \
		gobuffalo:mapi:v1.0.2:gobuffalo_mapi/vendor/github.com/gobuffalo/mapi \
		gobuffalo:packd:a385830c7fc0:gobuffalo_packd/vendor/github.com/gobuffalo/packd \
		gobuffalo:syncx:33c29581e754:gobuffalo_syncx/vendor/github.com/gobuffalo/syncx \
		golang:crypto:c2843e01d9a2:golang_crypto/vendor/golang.org/x/crypto \
		golang:sync:56d357773e84:golang_sync/vendor/golang.org/x/sync \
		golang:sys:d0b11bdaac8a:golang_sys/vendor/golang.org/x/sys \
		golang:tools:9c9e1878f421:golang_tools/vendor/golang.org/x/tools \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		joho:godotenv:v1.3.0:joho_godotenv/vendor/github.com/joho/godotenv \
		karrick:godirwalk:v1.8.0:karrick_godirwalk/vendor/github.com/karrick/godirwalk \
		markbates:oncer:bf2de49a0be2:markbates_oncer/vendor/github.com/markbates/oncer \
		markbates:safe:v1.0.1:markbates_safe/vendor/github.com/markbates/safe \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		rogpeppe:go-internal:v1.3.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		sirupsen:logrus:v1.4.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:cobra:v0.0.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag

post-extract:
		@${MKDIR} ${WRKSRC}/vendor/github.com/gobuffalo/packr
		@${LN} -s ${WRKSRC}/v2 ${WRKSRC}/vendor/github.com/gobuffalo/packr/v2

PLIST_FILES=	bin/packr \
		bin/packr2

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
