PORTNAME=	pgroonga
DISTVERSION=	3.2.2
CATEGORIES=	databases textproc
MASTER_SITES=	http://packages.groonga.org/source/pgroonga/

PATCH_SITES=	https://github.com/abetomo/pgroonga/commit/
PATCHFILES=	c01fffd7d68aca2ba87b675fe9a8bf80d23f2f1a.patch:-p1

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Open-source fulltext search engine for PostGRESQL
WWW=		https://pgroonga.github.io/

LICENSE=	PostgreSQL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgroonga.so:textproc/groonga

USES=		gmake localbase pgsql:13+ pkgconfig

CPPFLAGS+=	-I${LOCALBASE}/include/groonga
LLD_UNSAFE=	yes

SUB_FILES=	pkg-message

PLIST_SUB=	MVER=${DISTVERSION}

OPTIONS_DEFINE=		MECAB

MECAB_DESC=		Use MeCab as a tokenizer

MECAB_BUILD_DEPENDS=	mecab-ipadics>=0.996:japanese/mecab-ipadic

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pgroonga*.so

.include <bsd.port.mk>
