# $FreeBSD$

PORTNAME=	ksql
PORTVERSION=	0.1.3
CATEGORIES=	devel databases
MASTER_SITES=	http://kristaps.bsd.lv/ksql/snapshots/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Lazy man's wrapper for the SQLite C API

LICENSE=	ISCL

BUILD_DEPENDS=	${LOCALBASE}/include/sqlite3.h:databases/sqlite3

USES=		localbase

HAS_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} 's@^PREFIX="/usr/local"@PREFIX="${STAGEDIR}${PREFIX}"@' \
		${WRKSRC}/configure

do-test:
	@cd ${WRKSRC} && ./test

.include <bsd.port.mk>
