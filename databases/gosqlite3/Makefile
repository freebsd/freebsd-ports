# New ports collection makefile for:	gosqlite3
# Date created:				Apr 11, 2011
# Whom:					Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gosqlite3
PORTVERSION=	20110316
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	LOCAL/wen
DISTNAME=	${GITHUB_USER}-${PORTNAME}-${GIT_REVISION}

MAINTAINER=	lichray@gmail.com
COMMENT=	A Go interface for SQLite3

LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3

PLIST_FILES=	${GO_LIBDIR}/sqlite3.a

USE_GO=		yes
MAKE_ARGS+=	CGO_CFLAGS+="-I${LOCALBASE}/include" CFLAGS="-I${LOCALBASE}/${GO_LIBDIR}" CGO_LDFLAGS="-L${LOCALBASE}/lib -lsqlite3"

GITHUB_USER=	feyeleanor
GIT_REVISION=	0f3e536

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/go/files/bsd.go.mk"
.include <bsd.port.post.mk>
