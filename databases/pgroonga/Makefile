# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pgroonga
PORTVERSION=	2.2.5
PORTREVISION=	1
CATEGORIES=	databases textproc
MASTER_SITES=	http://packages.groonga.org/source/pgroonga/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Open-source fulltext search engine for PostGRESQL

LICENSE=	PostgreSQL

LIB_DEPENDS=	libgroonga.so:textproc/groonga

USES=		gmake pgsql pkgconfig

LLD_UNSAFE=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	MECAB
MECAB_DESC=	Use MeCab as a tokenizer
MECAB_BUILD_DEPENDS=	mecab-ipadics>=0.996:japanese/mecab-ipadic

.include <bsd.port.pre.mk>
# With PG11+ some scripts are only installed when they are common to
# all PG versions.
.if ${PGSQL_VER:R} < 11
PLIST_SUB+=     OLDPG="@comment "
.else
PLIST_SUB+=     OLDPG=""
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pgroonga.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pgroonga_check.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pgroonga_database.so

.include <bsd.port.post.mk>
