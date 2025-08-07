PORTNAME=	murmur-cli
PORTVERSION=	0.0.0.20200528
PORTREVISION=	28
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GRPC client for Murmur server
WWW=		https://github.com/layeh/murmur-cli

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

#GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
#GO_TARGET=	${GO_PKGNAME}/cmd/${GH_PROJECT}

PLIST_FILES=	bin/murmur-cli

GH_ACCOUNT=	layeh
GH_TAGNAME=	8f83169
USE_GITHUB=	yes
GH_TUPLE=	\
		golang:net:e7e4b65ae663:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:d0b11bdaac8a:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		google:go-genproto:24fa4b261c55:google_go_genproto/vendor/google.golang.org/genproto \
		grpc:grpc-go:v1.25.1:grpc_grpc_go/vendor/google.golang.org/grpc

.include <bsd.port.mk>
