# $FreeBSD$

PORTNAME=	prototool
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Swiss army knife for protocol buffers (ProtoBuf)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	uber
GH_TUPLE=	\
		cpuguy83:go-md2man:v1.0.10:cpuguy83_go_md2man/vendor/github.com/cpuguy83/go-md2man \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		emicklei:proto:v1.7.0:emicklei_proto/vendor/github.com/emicklei/proto \
		fullstorydev:grpcurl:v1.4.0:fullstorydev_grpcurl/vendor/github.com/fullstorydev/grpcurl \
		go-yaml:yaml:v2.2.4:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gobuffalo:flect:v0.1.6:gobuffalo_flect/vendor/github.com/gobuffalo/flect \
		gofrs:flock:v0.7.1:gofrs_flock/vendor/github.com/gofrs/flock \
		golang:net:d66e71096ffb:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:b09406accb47:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:go-genproto:548a555dbc03:google_go_genproto/vendor/google.golang.org/genproto \
		grpc:grpc-go:v1.24.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jhump:protoreflect:v1.5.0:jhump_protoreflect/vendor/github.com/jhump/protoreflect \
		mitchellh:go-wordwrap:v1.0.0:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		russross:blackfriday:v1.5.2:russross_blackfriday/vendor/github.com/russross/blackfriday \
		spf13:cobra:v0.0.5:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.4.0:stretchr_testify/vendor/github.com/stretchr/testify \
		uber-go:atomic:v1.4.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.2.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.10.0:uber_go_zap/vendor/go.uber.org/zap
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
