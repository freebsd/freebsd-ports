# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	gosqlite3
PORTVERSION=	20120330
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	LOCAL/jlaffaye

MAINTAINER=	lichray@gmail.com
COMMENT=	A Go interface for SQLite3

LIB_DEPENDS+=	libsqlite3.so:${PORTSDIR}/databases/sqlite3

GO_PKGNAME=	github.com/kuroneko/${PORTNAME}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
