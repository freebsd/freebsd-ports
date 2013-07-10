# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-sql3
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure language binding to the SQLite3 library

LIB_DEPENDS=	sqlite3:${PORTSDIR}/databases/sqlite3

USE_PURE=	yes

PLIST_FILES=	lib/pure/sql3.pure \
		lib/pure/sql3util.so

.include "${PORTSDIR}/lang/pure/bsd.pure.mk"
.include <bsd.port.mk>
