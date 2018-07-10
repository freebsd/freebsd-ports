# $FreeBSD$

PORTNAME=	vegeta
DISTVERSIONPREFIX=	v
DISTVERSION=	8.0.0
PORTREVISION=	1
CATEGORIES=	benchmarks www

MAINTAINER=	egypcio@googlemail.com
COMMENT=	HTTP load testing tool and library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

PLIST_FILES=	bin/${PORTNAME}

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	tsenart
GH_TUPLE=	streadway:quantile:b0c5887:quantile/github.com/streadway/quantile \
		golang:net:ed29d75:net/golang.org/x/net \
		golang:text:v0.3.0:text/golang.org/x/text \
		lucasb-eyer:go-colorful:v1.0:colorful/github.com/lucasb-eyer/go-colorful

do-build:
	@${MKDIR} ${WRKSRC}/github.com/${GH_ACCOUNT}
	@${RLN} ${WRKSRC} ${WRKSRC}/github.com/${GH_ACCOUNT}/${PORTNAME}
	@${RLN} ${WRKSRC} ${WRKSRC}/src
	@cd ${WRKSRC} && \
	  ${SETENV} ${MAKE_ENV} ${GO_ENV} CGO_ENABLED=0 GOPATH=${WRKSRC} \
	  ${GO_CMD} build -ldflags "-X main.Version=${DISTVERSION}" -o bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}/${LOCALBASE}/bin

.include <bsd.port.mk>
