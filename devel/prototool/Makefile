PORTNAME=	prototool
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.0
PORTREVISION=	28
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Swiss army knife for protocol buffers (ProtoBuf)
WWW=		https://github.com/uber/prototool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	uber
GH_TUPLE=	\
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		emicklei:proto:v1.9.0:emicklei_proto/vendor/github.com/emicklei/proto \
		fullstorydev:grpcurl:v1.4.0:fullstorydev_grpcurl/vendor/github.com/fullstorydev/grpcurl \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobuffalo:flect:v0.2.1:gobuffalo_flect/vendor/github.com/gobuffalo/flect \
		gofrs:flock:v0.7.1:gofrs_flock/vendor/github.com/gofrs/flock \
		golang:lint:738671d3881b:golang_lint/vendor/golang.org/x/lint \
		golang:net:244492dfa37a:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.4:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:5c8b2ff67527:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:tools:c807066ff753:golang_tools/vendor/golang.org/x/tools \
		google:go-genproto:b662892dd51b:google_go_genproto/vendor/google.golang.org/genproto \
		grpc:grpc-go:v1.28.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jhump:protoreflect:v1.6.0:jhump_protoreflect/vendor/github.com/jhump/protoreflect \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		russross:blackfriday:v2.0.1:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		shurcooL:sanitized_anchor_name:v1.0.0:shurcool_sanitized_anchor_name/vendor/github.com/shurcooL/sanitized_anchor_name \
		spf13:cobra:v0.0.6:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.5.1:stretchr_testify/vendor/github.com/stretchr/testify \
		uber-go:atomic:v1.6.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.5.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.14.0:uber_go_zap/vendor/go.uber.org/zap
GO_TARGET=	./cmd/prototool

PLIST_FILES=	bin/${PORTNAME} \
		etc/bash_completion.d/prototool \
		etc/zsh/site-functions/_prototool

post-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} run ${GO_BUILDFLAGS} ./internal/cmd/gen-prototool-bash-completion/main.go > prototool-bash-completion && \
		${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} run ${GO_BUILDFLAGS} ./internal/cmd/gen-prototool-zsh-completion/main.go > prototool-zsh-completion

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/prototool-bash-completion ${STAGEDIR}${PREFIX}/etc/bash_completion.d/prototool
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/prototool-zsh-completion ${STAGEDIR}${PREFIX}/etc/zsh/site-functions/_prototool

.include <bsd.port.mk>
