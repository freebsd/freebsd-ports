# New ports collection makefile for:	clip
# Date created:			Dec 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	clip
PORTVERSION=	1.1.14.1
PORTREVISION=	2
CATEGORIES=	databases lang
MASTER_SITES=	ftp://ftp.linux.ru.net/mirrors/clip/	\
		ftp://ftp.itk.ru/pub/clip/		\
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=lawrance
DISTFILES=	${PORTNAME}-prg-${PORTVERSION:R}-${PORTVERSION:E}.tgz \
		patch.tgz
DIST_SUBDIR=	clip
EXTRACT_ONLY=	${PORTNAME}-prg-${PORTVERSION:R}-${PORTVERSION:E}.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	xBase and Clipper language compatible compiler

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash			\
		wget:${PORTSDIR}/ftp/wget			\
		xmkmf:${X_IMAKE_PORT}
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg		\
		png.5:${PORTSDIR}/graphics/png			\
		freetype.9:${PORTSDIR}/print/freetype2		\
		gtkextra.17:${PORTSDIR}/x11-toolkits/gtkextra	\
		gd.4:${PORTSDIR}/graphics/gd			\
		fcgi.0:${PORTSDIR}/www/fcgi
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash			\
		wget:${PORTSDIR}/ftp/wget

WRKSRC=		${WRKDIR}/${PORTNAME}-prg-${PORTVERSION:R}-${PORTVERSION:E}
USE_GETTEXT=	yes
WANT_GNOME=	yes

OPTIONS=	IODBC		"iODBC support"				on \
		UNIXODBC	"unixODBC support (not with iODBC)"	off \
		MYSQL		"MySQL support"				off \
		PGSQL		"PostgreSQL support"			off \
		FIREBIRD	"Firebird (Interbase) support"		off

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile"
.endif

# OPT_CLIPLIBS contains the optional subdirectories built by
# the patched ${WRKSRC}/cliplibs/Makefile
# Not currently built: clip-oracle

# Either IODBC or UNIXODBC
.if defined(WITH_IODBC)
LIB_DEPENDS+=	iodbc.3:${PORTSDIR}/databases/libiodbc
PLIST_SUB=	ODBC=""
OPT_CLIPLIBS+=clip-odbc
.elif defined(WITH_UNIXODBC)
LIB_DEPENDS+=	odbc.1:${PORTSDIR}/databases/unixODBC
PLIST_SUB=	ODBC=""
OPT_CLIPLIBS+=clip-odbc
.else
PLIST_SUB=	ODBC="@comment "
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
PLIST_SUB+=	MYSQL=""
OPT_CLIPLIBS+=clip-mysql
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
PLIST_SUB+=	PGSQL=""
OPT_CLIPLIBS+=clip-postgres
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(WITH_FIREBIRD)
LIB_DEPENDS+=	gds.1:${PORTSDIR}/${FIREBIRD_PORT}
PLIST_SUB+=	IBASE=""
OPT_CLIPLIBS+=clip-interbase
.else
PLIST_SUB+=	IBASE="@comment "
.endif

USE_BISON=		yes
USE_GMAKE=		yes
USE_ICONV=		yes
USE_REINPLACE=		yes
REINPLACE_ARGS=		-i ""
USE_XLIB=		yes
USE_XPM=		yes
USE_GNOME=		gtk12 gtk20
HAS_CONFIGURE=		yes
CONFIGURE_WRKSRC=	${WRKSRC}/clip
INSTALLS_SHLIB=		yes
LDCONFIG_DIRS=		${LOCALBASE}/clip/lib
ALL_TARGET=		local
MAKE_ENV=		HOME="${WRKDIR}" \
			LANG="C" \
			PGLIBDIR="${LOCALBASE}/lib" \
			PGINCDIR="${LOCALBASE}/include" \
			OPT_CLIPLIBS="${OPT_CLIPLIBS}" \
			PTHREAD_LIBS="${PTHREAD_LIBS}" \
			LOCALBASE="${LOCALBASE}" \
			WITH_IODBC="${WITH_IODBC}" \
			CLIP_CONFIGURE_FLAGS="-l"

PKGMESSAGE=	${WRKDIR}/pkg-message

FIREBIRD_PORT?=	databases/firebird-client

BIN2STRIP=	bdbf clip clip_bl clip_blank clip_cld clip_conv clip_dbf2txt	\
		clip_dbg clip_fl clip_hashextract clip_hindex clip_hseek	\
		clip_hv clip_prg clip_run clip_trans clip_we clipar cliphash	\
		cobra_clnt1 cobra_serv codb_ab codb_abx codb_addobj codb_export \
		codb_make codb_pack codb_reindex ctosgml dbc	\
		ftosgml gen_tbl po_compat po_extr po_subst pp_ron sqlrun	\
		wcl2prg www_clip xclip

pre-everything::
	@if [ ! -z "${CLIPROOT}" ]; then \
		${ECHO} Please unset CLIPROOT in your environment! ; \
		exit 1; \
	fi

pre-patch:
	@cd ${WRKSRC} && ${PAX} -z -r -s '/clip-prg//' -f ${DISTDIR}/${DIST_SUBDIR}/patch.tgz

pre-configure:
	@${FIND} ${WRKSRC} -name "Makefile*" -or -name Imakefile |		\
	${XARGS} ${REINPLACE_CMD}						\
	-e "s|-Wall -g|${CFLAGS}|;s|-g -Wall|${CFLAGS}|;s|-Wall|${CFLAGS}|"	\
	-e "s|gcc|${CC}|;s|-O2||;s|-O ||;"
	@${FIND} ${WRKSRC} -name configure | ${XARGS} ${REINPLACE_CMD}		\
	-e "s|-Wall -g|${CFLAGS}|;s|-g -Wall|${CFLAGS}|;s|-Wall|${CFLAGS}|"	\
	-e "s|-O2||"
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD}			\
	-e "s|#include.*<malloc.h>|#include <stdlib.h>|"			\
	-e "s|#!/bin/sh|#!${LOCALBASE}/bin/bash|"				\
	-e "s|/usr/local|${LOCALBASE}|g"					\
	-e "s|/usr/X11R6|${X11BASE}|g"

post-build: # don't include emppty directories
	@cd ${WRKDIR}/cliproot && ${RMDIR} include/memdebug doc/clip-oasis/nanfor doc/clip-oasis

do-install:
	@${MKDIR} ${PREFIX}/clip
	@${CP} -R ${WRKDIR}/cliproot/* ${PREFIX}/clip
.for FILE in ${BIN2STRIP}
	@${STRIP_CMD} ${PREFIX}/clip/bin/${FILE}
.endfor
	@for f in `${LS} ${PREFIX}/clip/lib/*.so` ;				\
	do									\
		${STRIP_CMD} $$f ;				\
	done

post-install:
	@${SED} 's+/usr/local+${PREFIX}+' <${.CURDIR}/pkg-message >${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
