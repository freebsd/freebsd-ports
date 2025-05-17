PORTNAME=	ksql
PORTVERSION=	0.3.5
PORTREVISION=	1
CATEGORIES=	devel databases
MASTER_SITES=	http://kristaps.bsd.lv/ksql/snapshots/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lazy man's wrapper for the SQLite C API
WWW=		https://kristaps.bsd.lv/ksql/

LICENSE=	ISCL

DEPRECATED=	Last activity upstream 7 years ago, unmaintained in tree for several years and no consumers
EXPIRATION_DATE=2025-06-30

USES=		localbase:ldflags sqlite

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	PREFIX="${PREFIX}" LDFLAGS="${LDFLAGS}" MANDIR="${PREFIX}/share/man"

do-test:
	@cd ${WRKSRC} && ./test

.include <bsd.port.mk>
