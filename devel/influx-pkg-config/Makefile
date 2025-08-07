PORTNAME=	pkg-config
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.14
PORTREVISION=	5
CATEGORIES=	devel
PKGNAMEPREFIX=	influx

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Drop-in pkg-config replacement for compiling C libraries for InfluxData
WWW=		https://github.com/influxdata/pkg-config

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules pkgconfig:run

GO_MODULE=	github.com/influxdata/pkg-config
GO_TARGET=	./:${PREFIX}/bin/influx-pkg-config

PLIST_FILES=	bin/influx-pkg-config

.include <bsd.port.mk>
