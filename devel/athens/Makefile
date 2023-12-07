PORTNAME=	athens
PORTVERSION=	0.12.1
PORTREVISION=	3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Proxy server for the Go Modules download API
WWW=		https://github.com/gomods/athens

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

BUILD_DATE=	2023-04-27-00:00:00-UTC

GO_MODULE=	github.com/gomods/${PORTNAME}
GO_TARGET=	./cmd/proxy
GO_BUILDFLAGS=	-ldflags " \
		-X github.com/gomods/${PORTNAME}/pkg/build.version=${PORTVERSION} \
		-X github.com/gomods/${PORTNAME}/pkg/build.buildDate=${BUILD_DATE}"

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/proxy ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
