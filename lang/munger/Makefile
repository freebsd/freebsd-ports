# Created by: James Bailie <jimmy@mammothcheese.ca>
# $FreeBSD$

PORTNAME=	munger
PORTVERSION=	5.7
CATEGORIES=	lang
MASTER_SITES=	http://www.mammothcheese.ca/

MAINTAINER=	jimmy@mammothcheese.ca
COMMENT=	Static lisp interpreter with text processing abilities

LIB_DEPENDS=	libtre.so:${PORTSDIR}/textproc/libtre

DATADIR=	${PREFIX}/share/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	SQLITE
OPTIONS_DEFAULT=	SQLITE

SQLITE_USE=	SQLITE=3
SQLITE_MAKE_ARGS=	-DWITH_SQL

.include <bsd.port.mk>
