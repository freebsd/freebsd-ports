# $FreeBSD$

PORTNAME=	packr
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2
CATEGORIES=	devel

MAINTAINER=	dg@syrec.org
COMMENT=	Simple and easy way to embed static files into Go binaries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go

GO_PKGNAME=	github.com/gobuffalo/packr
GO_TARGET=	./packr \
		./v2/packr2

USE_GITHUB=	yes
GH_ACCOUNT=	gobuffalo
GH_TUPLE=	\
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		gobuffalo:buffalo-plugins:v1.12.0:gobuffalo_buffalo_plugins/vendor/github.com/gobuffalo/buffalo-plugins \
		gobuffalo:envy:v1.6.15:gobuffalo_envy/vendor/github.com/gobuffalo/envy \
		gobuffalo:events:v1.2.0:gobuffalo_events/vendor/github.com/gobuffalo/events \
		gobuffalo:flect:v0.1.0:gobuffalo_flect/vendor/github.com/gobuffalo/flect \
		gobuffalo:genny:c950828:gobuffalo_genny/vendor/github.com/gobuffalo/genny \
		gobuffalo:gogen:1c60761:gobuffalo_gogen/vendor/github.com/gobuffalo/gogen \
		gobuffalo:logger:be78ebf:gobuffalo_logger/vendor/github.com/gobuffalo/logger \
		gobuffalo:mapi:v1.0.1:gobuffalo_mapi/vendor/github.com/gobuffalo/mapi \
		gobuffalo:meta:ecaa953:gobuffalo_meta/vendor/github.com/gobuffalo/meta \
		gobuffalo:packd:d04dd98:gobuffalo_packd/vendor/github.com/gobuffalo/packd \
		gobuffalo:syncx:558ac7d:gobuffalo_syncx/vendor/github.com/gobuffalo/syncx \
		golang:crypto:74369b4:golang_crypto/vendor/golang.org/x/crypto \
		golang:sync:37e7f08:golang_sync/vendor/golang.org/x/sync \
		golang:sys:11f53e0:golang_sys/vendor/golang.org/x/sys \
		golang:tools:83362c3:golang_tools/vendor/golang.org/x/tools \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		joho:godotenv:v1.3.0:joho_godotenv/vendor/github.com/joho/godotenv \
		karrick:godirwalk:v1.7.8:karrick_godirwalk/vendor/github.com/karrick/godirwalk \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		markbates:oncer:bf2de49:markbates_oncer/vendor/github.com/markbates/oncer \
		markbates:safe:v1.0.1:markbates_safe/vendor/github.com/markbates/safe \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		rogpeppe:go-internal:v1.2.2:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		sirupsen:logrus:v1.3.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:cobra:v0.0.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag

PLIST_FILES=	bin/packr \
		bin/packr2

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
