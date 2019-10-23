# $FreeBSD$

PORTNAME=	goswagger
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21.0
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
		asaskevich:govalidator:f61b66f89f4a:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		corbym:gocrest:v1.0.3:corbym_gocrest/vendor/github.com/corbym/gocrest \
		coreos:go-oidc:v2.1.0:coreos_go_oidc/vendor/github.com/coreos/go-oidc \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-openapi:analysis:v0.19.5:go_openapi_analysis/vendor/github.com/go-openapi/analysis \
		go-openapi:errors:v0.19.2:go_openapi_errors/vendor/github.com/go-openapi/errors \
		go-openapi:inflect:v0.19.0:go_openapi_inflect/vendor/github.com/go-openapi/inflect \
		go-openapi:jsonpointer:v0.19.3:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.19.2:go_openapi_jsonreference/vendor/github.com/go-openapi/jsonreference \
		go-openapi:loads:v0.19.3:go_openapi_loads/vendor/github.com/go-openapi/loads \
		go-openapi:runtime:v0.19.5:go_openapi_runtime/vendor/github.com/go-openapi/runtime \
		go-openapi:spec:v0.19.3:go_openapi_spec/vendor/github.com/go-openapi/spec \
		go-openapi:strfmt:v0.19.3:go_openapi_strfmt/vendor/github.com/go-openapi/strfmt \
		go-openapi:swag:v0.19.5:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-openapi:validate:v0.19.3:go_openapi_validate/vendor/github.com/go-openapi/validate \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-swagger:scan-repo-boundary:973b3573c013:go_swagger_scan_repo_boundary/vendor/github.com/go-swagger/scan-repo-boundary \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.2:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:71b5226ff739:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:ba9fcec4b297:golang_net/vendor/golang.org/x/net \
		golang:oauth2:0f29369cfe45:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:d223b2b6db03:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:tools:2ca718005c18:golang_tools/vendor/golang.org/x/tools \
		gorilla:handlers:v1.4.2:gorilla_handlers/vendor/github.com/gorilla/handlers \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		jessevdk:go-flags:v1.4.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		kr:pretty:v0.1.0:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.1.0:kr_text/vendor/github.com/kr/text \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mailru:easyjson:b2ccc519800e:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mongodb:mongo-go-driver:v1.1.1:mongodb_mongo_go_driver/vendor/go.mongodb.org/mongo-driver \
		pelletier:go-toml:v1.4.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		pquerna:cachecontrol:1555304b9b35:pquerna_cachecontrol/vendor/github.com/pquerna/cachecontrol \
		spf13:afero:v1.2.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.4.0:spf13_viper/vendor/github.com/spf13/viper \
		square:go-jose:v2.3.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		toqueteos:webbrowser:v1.2.0:toqueteos_webbrowser/vendor/github.com/toqueteos/webbrowser

GO_TARGET=	./cmd/swagger

PLIST_FILES=	bin/swagger

.include <bsd.port.mk>
