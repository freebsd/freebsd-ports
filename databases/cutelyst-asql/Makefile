PORTNAME=	asql
DISTVERSIONPREFIX=	v
DISTVERSION=	0.27.0
PORTREVISION=	1
CATEGORIES=	databases
PKGNAMEPREFIX=	cutelyst-

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Qt async SQL library (for Postgres)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# TODO: once there are multiple (selectable) backends, introduce
# 	OPTIONS to toggle them, so we're not always depending on pgsql
USES=		cmake compiler:c++11-lang localbase pgsql qt:5
USE_GITHUB=	yes
USE_LDCONFIG=	yes
USE_QT=		qmake_build buildtools_build \
		core

GH_ACCOUNT=	cutelyst

PLIST_SUB=	SOVER=${DISTVERSION}

.include <bsd.port.mk>
