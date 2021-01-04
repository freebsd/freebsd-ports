# Created by: Matthias Fechner <mfechner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpg_query
DISTVERSION=	10-1.0.4
PORTREVISION=	0
CATEGORIES=	databases devel

PATCH_SITES=	https://github.com/lfittl/libpg_query/commit/
PATCHFILES=	820f5294f92927d6c4f61722bb28cf380942b83c.patch:-p1

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	C library for accessing the PostgreSQL parser outside of the server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c11 gmake pgsql
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	lfittl

do-install:
	${INSTALL_DATA} ${WRKSRC}/libpg_query.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/pg_query.h ${STAGEDIR}${PREFIX}/include/

PLIST_FILES=	include/pg_query.h \
		lib/libpg_query.a

.include <bsd.port.mk>
