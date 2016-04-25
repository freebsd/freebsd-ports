# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	gosqlite3
PORTVERSION=	20120330
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	LOCAL/jlaffaye

MAINTAINER=	lichray@gmail.com
COMMENT=	Go interface for SQLite3

USES=		compiler go

LIB_DEPENDS+=	libsqlite3.so:databases/sqlite3

GO_PKGNAME=	github.com/kuroneko/${PORTNAME}

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang && ${CC} == cc
CC=	clang
.endif

.include <bsd.port.post.mk>
