PORTNAME=	pgroonga
DISTVERSION=	4.0.2
CATEGORIES=	databases textproc
MASTER_SITES=	http://packages.groonga.org/source/pgroonga/

# For other MAINTAINERs, please be mindful of the sequences
# of release of Groonga and PGroonga. Althought the upstream
# mentions that PGroonga is compatible with other versions of
# Groonga, it is recommended to follow the sequence of release
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
