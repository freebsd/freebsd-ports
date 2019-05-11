# Created by: Jev Björsell <ports@ecadlabs.com>
# $FreeBSD$

PORTNAME=	redis_exporter
PORTVERSION=	0.34.0
DISTVERSIONPREFIX=v
CATEGORIES=	databases

MAINTAINER=	arcade@b1t.name
COMMENT=	Prometheus exporter for redis stats

LICENSE=	MIT

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	oliver006

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/redis_exporter

USE_RC_SUBR=	redis_exporter

LD_FLAG_X_PREFIX=	-X main
LD_FLAG_STRING=		-s \
		${LD_FLAG_X_PREFIX}.BuildVersion=${PORTVERSION}
GO_BUILDFLAGS=	-v -ldflags "${LD_FLAG_STRING}"

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/redis_exporter ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
