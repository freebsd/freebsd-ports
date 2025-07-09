PORTNAME=	influxdb2-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.5
PORTREVISION=	9
CATEGORIES=	databases net-mgmt

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	CLI for managing resources in InfluxDB v2
WWW=		https://github.com/influxdata/influx-cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	nodefault
GH_TUPLE=	golang:sys:v0.6.0:sys

GO_MODULE=	github.com/influxdata/influx-cli/v2
GO_TARGET=	./cmd/influx

CONFLICTS_INSTALL=	influxdb

PLIST_FILES=	bin/influx

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${LN} -s ${WRKDIR}/sys-* ${WRKSRC}/vendor/golang.org/x/sys

.include <bsd.port.mk>
