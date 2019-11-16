# $FreeBSD$

PORTNAME=	packr
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Simple and easy way to embed static files into Go binaries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	gobuffalo
GH_TUPLE=	\
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobuffalo:envy:v1.7.1:gobuffalo_envy/vendor/github.com/gobuffalo/envy \
		gobuffalo:logger:v1.0.1:gobuffalo_logger/vendor/github.com/gobuffalo/logger \
		gobuffalo:packd:v0.3.0:gobuffalo_packd/vendor/github.com/gobuffalo/packd \
		golang:crypto:cc06ce4a13d4:golang_crypto/vendor/golang.org/x/crypto \
		golang:sync:cd5d95a43a6e:golang_sync/vendor/golang.org/x/sync \
		golang:sys:06a5c4944438:golang_sys/vendor/golang.org/x/sys \
		golang:tools:72853e10c5a3:golang_tools/vendor/golang.org/x/tools \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		joho:godotenv:v1.3.0:joho_godotenv/vendor/github.com/joho/godotenv \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rogpeppe:go-internal:v1.4.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag

GO_TARGET=	./packr \
		./v2/packr2

PLIST_FILES=	bin/packr \
		bin/packr2

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} ${WRKSRC}/v2/go.mod

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
