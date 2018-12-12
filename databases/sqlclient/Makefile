# $FreeBSD$

PORTNAME=	sqlclient
PORTVERSION=	1.8.1
PORTREVISION=	6
CATEGORIES=	databases gnustep
MASTER_SITES=	GNUSTEP/libs
DISTNAME=	SQLClient-${PORTVERSION}

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	Lightweight database abstraction layer

LICENSE=	LGPL21

LIB_DEPENDS=	libPerformance.so:devel/performance \
		libsqlite3.so:databases/sqlite3

USES=		gnustep pgsql
USE_GNUSTEP=	base build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	${GNUSTEP_LOCAL_LIBRARIES}
USE_MYSQL=yes

LDFLAGS+=	-pthread
DEFAULT_LIBVERSION=	1.5
DEFAULT_LIBVERSION2=	1.5.0
PLIST_SUB+=	LIBVERSION2=${DEFAULT_LIBVERSION2}
PLIST_SUB+=	MAJORLIBVERSION2=${DEFAULT_LIBVERSION2:C/([0-9]).*/\1/1}

.include <bsd.port.mk>
