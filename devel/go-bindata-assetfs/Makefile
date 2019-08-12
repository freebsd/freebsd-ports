# $FreeBSD$

PORTNAME=	go-bindata-assetfs
PORTVERSION=	g20180223
CATEGORIES=	devel www

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Serves embedded files from go-bindata with Go's net/http support

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	go-bindata>=0:devel/go-bindata

USES=		go
USE_GITHUB=	nodefault

GO_PKGNAME=	github.com/elazarl/${PORTNAME}/${PORTNAME}
GH_TUPLE=	elazarl:${PORTNAME}:38087fe:elazarl_gbd/github.com/elazarl/${PORTNAME} \
		golang:net:ca1201d:golang_net/golang.org/x/net \
		golang:sys:51ab0e2:golang_sys/golang.org/x/sys \

PLIST_FILES=	bin/${PORTNAME}

do-build:
	@cd ${WRKSRC} && \
	  ${RLN} ${WRKSRC} src && \
	  ${SETENV} ${MAKE_ENV} ${GO_ENV} GOPATH=${WRKSRC} ${GO_CMD} \
	  build ${GO_BUILDFLAGS} -o bin/${PORTNAME} ${GO_PKGNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
