# New ports collection makefile for:    clip
# Date created:                 Dec 23, 2001
# Whom:                         ijliao
#
# $FreeBSD$
#

PORTNAME=	clip
DISTVERSION=	1.2.0-0
CATEGORIES=	databases lang
MASTER_SITES=	SF/x-clip
DISTNAME=	${PORTNAME}-prg-${DISTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	clip

MAINTAINER=	dk.diklab@gmail.com
COMMENT=	Object oriented, xBase and Clipper language compatible compiler

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash			\
		wget:${PORTSDIR}/ftp/wget			\
		imake:${PORTSDIR}/devel/imake
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg		\
		png.5:${PORTSDIR}/graphics/png			\
		freetype.9:${PORTSDIR}/print/freetype2		\
		gtkextra.17:${PORTSDIR}/x11-toolkits/gtkextra	\
		gd.4:${PORTSDIR}/graphics/gd			\
		expat.6:${PORTSDIR}/textproc/expat2		\
		glade-2.0:${PORTSDIR}/devel/libglade2		\
		fcgi.0:${PORTSDIR}/www/fcgi
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash			\
		wget:${PORTSDIR}/ftp/wget

WRKSRC=		${WRKDIR}/${PORTNAME}-prg-${DISTVERSION}
USE_GETTEXT=	yes
USE_XORG+=	x11 xau ice xproto xmu xpm
WANT_GNOME=	yes
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	IODBC		"iODBC support"				on \
		UNIXODBC	"unixODBC support (not with iODBC)"	off \
		MYSQL		"MySQL support"				off \
		PGSQL		"PostgreSQL support"			off \
		FIREBIRD	"Firebird (Interbase) support"		off

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		Does not compile on !i386
.endif

# OPT_CLIPLIBS contains the optional subdirectories built by
# the patched ${WRKSRC}/cliplibs/Makefile
# Not currently built: clip-oracle

# Either IODBC or UNIXODBC
.if defined(WITH_IODBC) && defined(WITH_UNIXODBC)
IGNORE=		selected mutually exclusive options: WITH_IODBC and WITH_UNIXODBC
.endif

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
USE_FIREBIRD=	yes
PLIST_SUB+=	IBASE=""
OPT_CLIPLIBS+=clip-interbase
.else
PLIST_SUB+=	IBASE="@comment "
.endif

USE_BISON=		build
USE_GMAKE=		yes
USE_ICONV=		yes
REINPLACE_ARGS=		-i ""
USE_XORG+=		xpm xau ice xproto
USE_GNOME=		gtk12 gtk20
HAS_CONFIGURE=		yes
CONFIGURE_WRKSRC=	${WRKSRC}/clip
USE_LDCONFIG=		${LOCALBASE}/clip/lib
ALL_TARGET=		local
MAKE_ENV=		HOME="${WRKDIR}" \
			LANG="C" \
			PGLIBDIR="${LOCALBASE}/lib" \
			PGINCDIR="${LOCALBASE}/include" \
			OPT_CLIPLIBS="${OPT_CLIPLIBS}" \
			PTHREAD_LIBS="${PTHREAD_LIBS}" \
			WITH_IODBC="${WITH_IODBC}" \
			CLIP_CONFIGURE_FLAGS="-l"

BIN2STRIP=	bdbf clip clip_bl clip_blank clip_cld clip_conv clip_dbf2txt	\
		clip_dbg clip_fl clip_hashextract clip_hindex clip_hseek	\
		clip_hv clip_prg clip_run clip_trans clip_we clipar cliphash	\
		cobra_clnt1 cobra_serv codb_ab codb_addobj codb_load codb_export\
		codb_make codb_pack codb_rcheck codb_reindex ctosgml dbc	\
		ftosgml gen_tbl po_compat po_extr po_subst pp_ron sqlrun	\
		wcl2prg www_clip xclip

DIR2PRUNE=	include/memdebug doc/clip-com doc/clip-oasis/nanfor doc/clip-oasis

pre-everything::
	@if [ ! -z "${CLIPROOT}" ]; then \
		${ECHO} Please unset CLIPROOT in your environment! ; \
		exit 1; \
	fi

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
	-e "s|/usr/X11R6|${LOCALBASE}|g"
	${REINPLACE_CMD} "s|-I/usr/include|-I${LOCALBASE}/include -L${LOCALBASE}/lib|"	\
		${WRKSRC}/cliplibs/clip-xml/configure
	${REINPLACE_CMD} -e "s|-I/usr/include|-I${LOCALBASE}/include|"		\
		-e "s|-lexpat|-L${LOCALBASE}/lib -lexpat|"			\
		${WRKSRC}/cliplibs/clip-xml/Makefile.in

post-build: # don't include emppty directories
	${RMDIR} ${DIR2PRUNE:S|^|${WRKDIR}/cliproot/|}

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
	@${CAT} ${PKGMESSAGE}

.if defined(MAINTAINER_MODE)
regression-test:	install
	(cd ${WRKSRC}/clip/tests &&	\
	CLIPROOT=${PREFIX}/clip PATH="${PATH}:${PREFIX}/clip/bin" ${GMAKE} all)
.endif

.include <bsd.port.post.mk>
