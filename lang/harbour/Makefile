# New ports collection makefile for:	Harbour
# Date created:				9 May 2003
# Whom:					David G. Holm <harbour@netfang.net>
#
# $FreeBSD$
#

PORTNAME=	harbour
PORTVERSION=	3.0.0
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}-project/source/${PORTVERSION}

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	An open source Clipper-compatible compiler

LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2\
		pcre:${PORTSDIR}/devel/pcre
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS=	MYSQL "MySQL database support" off \
		SQLITE3 "SQLite 3.x database support" off \
		FIREBIRD "Firebird (Interbase) database support" off \
		PGSQL "PostgreSQL database support" off \
		CLANG "Build harbour with Clang (gcc if disabled)" off

NOT_FOR_ARCHS=	sparc64
NOT_FOR_ARCHS_REASON=	does not compile on sparc64: assertion failed

PORTDOCS=	*.txt *.hbd NEWS INSTALL TODO COPYING ChangeLog

MAKE_JOBS_SAFE=	yes

USE_BISON=	build
USE_GMAKE=	yes
USE_OPENSSL=	yes
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

HB_INSTALL_PREFIX=	${LOCALBASE}
HB_BIN_INSTALL=	${LOCALBASE}/bin
HB_LIB_INSTALL=	${LOCALBASE}/lib
HB_INC_INSTALL=	${LOCALBASE}/include
HB_USER_CFLAGS=	-fPIC
HB_USER_LDFLAGS=	-L${LOCALBASE}/lib

MAKE_ENV=	HB_ARCHITECTURE=${HB_ARCH} \
		HB_COMPILER=${HB_COMPILER} \
		HB_GT_LIB=${HB_GT_LIB} \
		HB_INSTALL_PREFIX=${HB_INSTALL_PREFIX} \
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

.if !defined(NOPORTDOCS)
MAKE_ENV+=	HB_INSTALL_DOC=${DOCSDIR}
.else
MAKE_ENV+=	HB_INSTALL_DOC=no
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_CLANG)
HB_COMPILER=	clang
.if ${OSVERSION} < 900033
BUILD_DEPENDS+=	clang:${PORTSDIR}/lang/clang
.endif
.else
HB_COMPILER=	gcc
USE_GCC=	4.2+
.endif

.if defined(WITH_FIREBIRD)
USE_FIREBIRD=	yes
MAKE_ENV+=	HB_WITH_FIREBIRD=nolocal
.else
MAKE_ENV+=	HB_WITH_FIREBIRD=no
.endif

.if defined(WITH_SQLITE3)
LIB_DEPENDS+=	sqlite3:${PORTSDIR}/databases/sqlite3
MAKE_ENV+=	HB_WITH_SQLITE3=nolocal
PLIST_SUB+=	WITH_SQLITE3=""
.else
MAKE_ENV+=	HB_WITH_SQLITE3=no
PLIST_SUB+=	WITH_SQLITE3="@comment "
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
MAKE_ENV+=	HB_WITH_MYSQL=nolocal
.else
MAKE_ENV+=	HB_WITH_MYSQL=no
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
MAKE_ENV+=	HB_WITH_PGSQL=nolocal
.else
MAKE_ENV+=	HB_WITH_PGSQL=no
.endif

post-patch:
.if ${OSVERSION} > 900007
	${REINPLACE_CMD} \
		-e 's|utmp.h|utmpx.h|g' ${WRKSRC}/src/rtl/gtcrs/gtcrs.h
.endif

.include <bsd.port.post.mk>
