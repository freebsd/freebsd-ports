PORTNAME=	influxdb2-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.1
CATEGORIES=	databases net-mgmt

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	CLI for managing resources in InfluxDB v2
WWW=		https://github.com/influxdata/influx-cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_MODULE=	github.com/influxdata/influx-cli/v2
GO_TARGET=	./cmd/influx

CONFLICTS_INSTALL=	influxdb

PLIST_FILES=	bin/influx

.include <bsd.port.mk>
