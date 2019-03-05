# Created by: David G. Holm <harbour@netfang.net>
# $FreeBSD$

PORTNAME=	harbour
PORTVERSION=	3.0.0
PORTREVISION=	5
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}-project/source/${PORTVERSION}

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Open source Clipper-compatible compiler

LICENSE=	GPLv2

BROKEN_mips=		does not build: clang: Command not found
BROKEN_mips64=		does not build: clang: Command not found
# XXX MCL 20181112
#BROKEN_powerpc64=	does not build: clang: Command not found
BROKEN_sparc64=		does not compile: assertion failed
BROKEN_SSL=				libressl libressl-devel openssl111
BROKEN_SSL_REASON_libressl=		Needs an old version of OpenSSL (older than 1.1)
BROKEN_SSL_REASON_libressl-devel=	Needs an old version of OpenSSL (older than 1.1)
BROKEN_SSL_REASON_openssl111=		Needs an older version of OpenSSL (older than 1.1)

LIB_DEPENDS=	libslang.so:devel/libslang2\
		libpcre.so:devel/pcre
BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		bison gmake shebangfix ssl

SHEBANG_FILES=	bin/hb3rdpat.hbs
SHEBANG_LANG=	hbrun

OPTIONS_DEFINE=	MYSQL SQLITE FIREBIRD PGSQL DOCS
OPTIONS_SUB=	yes

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1200085 && ${SSL_DEFAULT} == base
BROKEN=	Needs an older version of OpenSSL (older than 1.1)
.endif

PORTDOCS=	*.txt *.hbd NEWS INSTALL TODO COPYING ChangeLog

USE_LDCONFIG=	${LOCALBASE}/lib/harbour

HB_WITH_ALLEGRO=	no
HB_WITH_CAIRO=	no
HB_WITH_CUPS=	no
HB_WITH_CURL=	no
HB_WITH_EXPAT=	local
HB_WITH_FREEIMAGE=	no
HB_WITH_GD=	no
HB_WITH_GS=	no
HB_WITH_JPEG=	no
HB_WITH_LIBMAGIC=	no
HB_WITH_MXML=	no
HB_WITH_ODBC=	no
HB_WITH_PCRE=	nolocal
HB_WITH_PNG=	no
HB_WITH_QT=	no
HB_WITH_SLANG=	nolocal
HB_WITH_X11=	no

HB_ARCH=	bsd
HB_GT_LIB=	gtsln
HB_COMPILER=	clang

HB_INSTALL_PREFIX=	${STAGEDIR}/${LOCALBASE}
HB_INSTALL_BIN=	${STAGEDIR}${LOCALBASE}/bin
HB_INSTALL_LIB=	${STAGEDIR}${LOCALBASE}/lib/harbour
HB_INSTALL_INC=	${STAGEDIR}${LOCALBASE}/include/harbour
HB_INSTALL_DOC=	${STAGEDIR}${DOCSDIR}
HB_USER_CFLAGS=	"${CFLAGS} -fPIC"
HB_USER_LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

MAKE_ENV=	HB_ARCHITECTURE=${HB_ARCH} \
		HB_BUILD_OPTIM=no \
		HB_COMPILER=${HB_COMPILER} \
		HB_GT_LIB=${HB_GT_LIB} \
		HB_INSTALL_PREFIX=${HB_INSTALL_PREFIX} \
		HB_INSTALL_BIN=${HB_INSTALL_BIN} \
		HB_INSTALL_LIB=${HB_INSTALL_LIB} \
		HB_INSTALL_INC=${HB_INSTALL_INC} \
		HB_WITH_ALLEGRO=${HB_WITH_ALLEGRO} \
		HB_WITH_CAIRO=${HB_WITH_CAIRO} \
		HB_WITH_CUPS=${HB_WITH_CUPS} \
		HB_WITH_CURL=${HB_WITH_CURL} \
		HB_WITH_EXPAT=${HB_WITH_EXPAT} \
		HB_WITH_FREEIMAGE=${HB_WITH_FREEIMAGE} \
		HB_WITH_GD=${HB_WITH_GD} \
		HB_WITH_GS=${HB_WITH_GS} \
		HB_WITH_JPEG=${HB_WITH_JPEG} \
		HB_WITH_LIBMAGIC=${HB_WITH_LIBMAGIC} \
		HB_WITH_MXML=${HB_WITH_MXML} \
		HB_WITH_ODBC=${HB_WITH_ODBC} \
		HB_WITH_PCRE=${HB_WITH_PCRE} \
		HB_WITH_QT=${HB_WITH_QT} \
		HB_WITH_SLANG=${HB_WITH_SLANG} \
		HB_WITH_X11=${HB_WITH_X11} \
		HB_USER_CFLAGS=${HB_USER_CFLAGS} \
		HB_USER_LDFLAGS=${HB_USER_LDFLAGS}

DOCS_MAKE_ENV=		HB_INSTALL_DOC=${HB_INSTALL_DOC}
DOCS_MAKE_ENV_OFF=	HB_INSTALL_DOC=no
PGSQL_USES=	pgsql
PGSQL_MAKE_ENV=		HB_WITH_PGSQL=${LOCALBASE}/include
PGSQL_MAKE_ENV_OFF=	HB_WITH_PGSQL=no
FIREBIRD_USES=	firebird
FIREBIRD_MAKE_ENV=	HB_WITH_FIREBIRD=${LOCALBASE}/include
FIREBIRD_MAKE_ENV_OFF=	HB_WITH_FIREBIRD=no
MYSQL_USES=	mysql
MYSQL_MAKE_ENV=		HB_WITH_MYSQL=${LOCALBASE}/include/mysql
MYSQL_MAKE_ENV_OFF=	HB_WITH_MYSQL=no
SQLITE_USES=	sqlite
SQLITE_MAKE_ENV=	HB_WITH_SQLITE3=${LOCALBASE}/include
SQLITE_MAKE_ENV_OFF=	HB_WITH_SQLITE3=no

post-patch:
	${REINPLACE_CMD} \
		-e 's|utmp.h|utmpx.h|g' ${WRKSRC}/src/rtl/gtcrs/gtcrs.h

# override default for gcc-based archs
.if ${ARCH:Mmips*} || ${ARCH:Mpowerpc*} || ${ARCH} == sparc64
HB_COMPILER=	gcc
.endif

.include <bsd.port.post.mk>
