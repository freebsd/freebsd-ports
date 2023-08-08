PORTNAME=	asql
DISTVERSIONPREFIX=	v
DISTVERSION=	0.80.0
CATEGORIES=	databases
PKGNAMEPREFIX=	cutelyst-

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Qt async SQL library (for Postgres)
WWW=		https://github.com/cutelyst/asql

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# TODO: once there are multiple (selectable) backends, introduce
# 	OPTIONS to toggle them, so we're not always depending on pgsql
USES=		cmake compiler:c++11-lang localbase pgsql qt:5
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_QT=		qmake:build buildtools:build \
		core

GH_ACCOUNT=	cutelyst

PLIST_SUB=	SOVER=${DISTVERSION}

.include <bsd.port.mk>
