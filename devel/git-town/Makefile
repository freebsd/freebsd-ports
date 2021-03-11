# $FreeBSD$

PORTNAME=	git-town
DISTVERSIONPREFIX=	v
DISTVERSION=	7.5.0
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Git extension for generic, high-level git workflow support

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	Originate

GH_TUPLE=	\
		AlecAivazis:survey:v1.8.8:alecaivazis_survey/vendor/gopkg.in/AlecAivazis/survey.v1 \
		acarl005:stripansi:5a71ef0e047d:acarl005_stripansi/vendor/github.com/acarl005/stripansi \
		cucumber:gherkin-go:v11.0.0:cucumber_gherkin_go_v11/vendor/github.com/cucumber/gherkin-go/v11 \
		cucumber:godog:v0.9.0:cucumber_godog/vendor/github.com/cucumber/godog \
		cucumber:messages-go:v10.0.3:cucumber_messages_go_v10/vendor/github.com/cucumber/messages-go/v10 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gofrs:uuid:v3.2.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		gogo:protobuf:v1.3.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.6:golang_appengine/vendor/google.golang.org/appengine \
		golang:net:ff2c4b7c35a0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:593003d681fa:golang_sys/vendor/golang.org/x/sys \
		google:go-github:v17.0.0:google_go_github/vendor/github.com/google/go-github \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		hashicorp:go-version:v1.2.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jarcoal:httpmock:61bcb58a0752:jarcoal_httpmock/vendor/gopkg.in/jarcoal/httpmock.v1 \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.21.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		sergi:go-diff:v1.0.0:sergi_go_diff/vendor/github.com/sergi/go-diff \
		spf13:cobra:v1.0.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.5.1:stretchr_testify/vendor/github.com/stretchr/testify

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-install-DOCS-on:
	cd ${WRKSRC}/documentation && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
