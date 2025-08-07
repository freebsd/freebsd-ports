PORTNAME=	usql
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19.18
PORTREVISION=	3
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal command-line interface for SQL databases
WWW=		https://github.com/xo/usql

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	fails to find resvg_xx symbols, see https://github.com/xo/usql/issues/494
BROKEN_armv7=	fails to find resvg_xx symbols, see https://github.com/xo/usql/issues/494
BROKEN_i386=	fails to find resvg_xx symbols, see https://github.com/xo/usql/issues/494

LIB_DEPENDS=	libresvg.so:graphics/resvg-capi

USES=		go:1.23,modules

GO_MODULE=	github.com/xo/usql

PLIST_FILES=	bin/usql

.include <bsd.port.mk>
