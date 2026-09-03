PORTNAME=	go-blueprint
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.11
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	hayzam@alchemilla.io
COMMENT=	CLI tool for setting up Go projects
WWW=		https://github.com/Melkeydev/go-blueprint

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go:modules,run
GO_MODULE=	github.com/Melkeydev/go-blueprint

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${REINPLACE_CMD} \
		-e 's|ExecuteCmd("go"|ExecuteCmd("${GO_CMD}"|g' \
		-e 's|ExecuteCmd("gofmt"|ExecuteCmd("${LOCALBASE}/bin/gofmt${GO_SUFFIX}"|g' \
		${WRKSRC}/cmd/utils/utils.go

.include <bsd.port.mk>
