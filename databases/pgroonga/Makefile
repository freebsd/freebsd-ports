PORTNAME=	pgroonga
PORTVERSION=	3.0.2
CATEGORIES=	databases textproc
MASTER_SITES=	http://packages.groonga.org/source/pgroonga/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Open-source fulltext search engine for PostGRESQL
WWW=		https://pgroonga.github.io/

LICENSE=	PostgreSQL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgroonga.so:textproc/groonga

USES=		gmake localbase pgsql:11+ pkgconfig

CPPFLAGS+=	-I${LOCALBASE}/include/groonga
LLD_UNSAFE=	yes
SUB_FILES=	pkg-message
PLIST_SUB=	MVER=${PORTVERSION}

OPTIONS_DEFINE=		MECAB
MECAB_DESC=		Use MeCab as a tokenizer
MECAB_BUILD_DEPENDS=	mecab-ipadics>=0.996:japanese/mecab-ipadic

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/pgroonga*.so

.include <bsd.port.mk>
