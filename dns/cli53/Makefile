PORTNAME=	cli53
DISTVERSION=	0.8.22
PORTREVISION=	5
CATEGORIES=	dns

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Command line tool for Amazon Route 53
WWW=		https://github.com/barnybug/cli53

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	barnybug
GH_TUPLE=	aws:aws-sdk-go:v1.44.207:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		cpuguy83:go-md2man:f79a8a8ca69d:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.0:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:089bfa567519:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.1.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.1.0:golang_sys/vendor/golang.org/x/sys \
		gucumber:gucumber:7d5c79e832a2:gucumber_gucumber/vendor/github.com/gucumber/gucumber \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		miekg:dns:v1.1.31:miekg_dns/vendor/github.com/miekg/dns \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		shiena:ansicolor:a422bbe96644:shiena_ansicolor/vendor/github.com/shiena/ansicolor \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		urfave:cli:v2.2.0:urfave_cli_v2/vendor/github.com/urfave/cli/v2

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./cmd/cli53

PLIST_FILES=	bin/cli53

.include <bsd.port.mk>
