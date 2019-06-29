# Created by: Jev Björsell <ports@ecadlabs.com>
# $FreeBSD$

PORTNAME=	redis_exporter
PORTVERSION=	1.0.3
DISTVERSIONPREFIX=v
CATEGORIES=	databases

MAINTAINER=	arcade@b1t.name
COMMENT=	Prometheus exporter for redis stats

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	oliver006
USE_RC_SUBR=	redis_exporter

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_BUILDFLAGS=	-v -ldflags "${LD_FLAG_STRING}"

PLIST_FILES=	bin/redis_exporter

LD_FLAG_X_PREFIX=	-X main
LD_FLAG_STRING=		-s \
		${LD_FLAG_X_PREFIX}.BuildVersion=${PORTVERSION}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/redis_exporter ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
