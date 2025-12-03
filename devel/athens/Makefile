PORTNAME=	athens
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.1
PORTREVISION=	6
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Proxy server for the Go Modules download API
WWW=		https://github.com/gomods/athens

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_RC_SUBR=	${PORTNAME}

GO_MODULE=	github.com/gomods/${PORTNAME}
GO_TARGET=	./cmd/proxy
GO_BUILDFLAGS=	-ldflags " \
		-X github.com/gomods/${PORTNAME}/pkg/build.version=${DISTVERSION} \
		-X github.com/gomods/${PORTNAME}/pkg/build.buildDate=${BUILD_DATE}"

SUB_LIST=	ATHENS_USER=${USERS} \
		ATHENS_GROUP=${GROUPS}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

BUILD_DATE=	2025-09-13-00:00:00-UTC

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/proxy ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/config.dev.toml ${STAGEDIR}${ETCDIR}/athens.toml.sample

.include <bsd.port.mk>
