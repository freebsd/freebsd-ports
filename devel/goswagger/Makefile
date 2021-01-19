# $FreeBSD$

PORTNAME=	goswagger
DISTVERSIONPREFIX=	v
DISTVERSION=	0.26.0
CATEGORIES=	devel

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Swagger 2.0 implementation for Go

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	go-swagger
GH_PROJECT=	go-swagger
GH_TUPLE=	\
		PuerkitoBio:purell:v1.1.1:puerkitobio_purell/vendor/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/vendor/github.com/PuerkitoBio/urlesc \
		asaskevich:govalidator:7a23bdc65eef:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		coreos:go-oidc:v2.2.1:coreos_go_oidc/vendor/github.com/coreos/go-oidc \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		felixge:httpsnoop:v1.0.1:felixge_httpsnoop/vendor/github.com/felixge/httpsnoop \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-ini:ini:v1.62.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-openapi:analysis:v0.19.16:go_openapi_analysis/vendor/github.com/go-openapi/analysis \
		go-openapi:errors:v0.19.9:go_openapi_errors/vendor/github.com/go-openapi/errors \
		go-openapi:inflect:v0.19.0:go_openapi_inflect/vendor/github.com/go-openapi/inflect \
		go-openapi:jsonpointer:v0.19.5:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.19.5:go_openapi_jsonreference/vendor/github.com/go-openapi/jsonreference \
		go-openapi:loads:v0.20.0:go_openapi_loads/vendor/github.com/go-openapi/loads \
		go-openapi:runtime:v0.19.26:go_openapi_runtime/vendor/github.com/go-openapi/runtime \
		go-openapi:spec:v0.20.1:go_openapi_spec/vendor/github.com/go-openapi/spec \
		go-openapi:strfmt:v0.20.0:go_openapi_strfmt/vendor/github.com/go-openapi/strfmt \
		go-openapi:swag:v0.19.13:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-openapi:validate:v0.20.1:go_openapi_validate/vendor/github.com/go-openapi/validate \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-swagger:scan-repo-boundary:973b3573c013:go_swagger_scan_repo_boundary/vendor/github.com/go-swagger/scan-repo-boundary \
		go-yaml:yaml:eeeca48fe776:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:c8d3bf9c5392:golang_crypto/vendor/golang.org/x/crypto \
		golang:mod:v0.3.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:6772e930b67b:golang_net/vendor/golang.org/x/net \
		golang:oauth2:9fd604954f58:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:771906719818:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.5:golang_text/vendor/golang.org/x/text \
		golang:tools:b5590deeca9b:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		gorilla:handlers:v1.5.1:gorilla_handlers/vendor/github.com/gorilla/handlers \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		jessevdk:go-flags:v1.4.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		josharian:intern:v1.0.0:josharian_intern/vendor/github.com/josharian/intern \
		kr:pretty:v0.2.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		magiconair:properties:v1.8.4:magiconair_properties/vendor/github.com/magiconair/properties \
		mailru:easyjson:v0.7.6:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mitchellh:mapstructure:v1.4.1:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mongodb:mongo-go-driver:v1.4.4:mongodb_mongo_go_driver/vendor/go.mongodb.org/mongo-driver \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		pelletier:go-toml:v1.8.1:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		pquerna:cachecontrol:858c6e7e6b7e:pquerna_cachecontrol/vendor/github.com/pquerna/cachecontrol \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		spf13:afero:v1.4.1:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.1:spf13_viper/vendor/github.com/spf13/viper \
		square:go-jose:v2.5.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		toqueteos:webbrowser:v1.2.0:toqueteos_webbrowser/vendor/github.com/toqueteos/webbrowser

GO_TARGET=	./cmd/swagger

PLIST_FILES=	bin/swagger

.include <bsd.port.mk>
