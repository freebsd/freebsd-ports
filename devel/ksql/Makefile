# $FreeBSD$

PORTNAME=	ksql
PORTVERSION=	0.3.1
CATEGORIES=	devel databases
MASTER_SITES=	http://kristaps.bsd.lv/ksql/snapshots/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Lazy man's wrapper for the SQLite C API

LICENSE=	ISCL

BUILD_DEPENDS=	${LOCALBASE}/include/sqlite3.h:databases/sqlite3

USES=		localbase

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	PREFIX="${PREFIX}"

do-test:
	@cd ${WRKSRC} && ./test

.include <bsd.port.mk>
