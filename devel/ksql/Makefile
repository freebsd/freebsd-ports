# $FreeBSD$

PORTNAME=	ksql
PORTVERSION=	0.3.5
CATEGORIES=	devel databases
MASTER_SITES=	http://kristaps.bsd.lv/ksql/snapshots/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Lazy man's wrapper for the SQLite C API

LICENSE=	ISCL

USES=		localbase:ldflags sqlite

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	PREFIX="${PREFIX}" LDFLAGS="${LDFLAGS}"

do-test:
	@cd ${WRKSRC} && ./test

.include <bsd.port.mk>
