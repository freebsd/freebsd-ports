# New ports collection makefile for:	clip
# Date created:			Dec 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	clip
PORTVERSION=	1.1.5.1
PORTREVISION=	1
CATEGORIES=	databases lang
MASTER_SITES=	ftp://ftp.linux.ru.net/mirrors/clip/	\
		ftp://ftp.lastik.ru/clip/		\
		ftp://ftp.itk.ru/pub/clip/
DISTNAME=	${PORTNAME}-prg-${PORTVERSION:R}-${PORTVERSION:E}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	xBase and Clipper language compatible compiler

USE_GETTEXT=	yes

WANT_GNOME=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.else
BROKEN=		"Broken pkg-plist"
.endif
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2004-06-18

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash2			\
		wget:${PORTSDIR}/ftp/wget
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg		\
		png.5:${PORTSDIR}/graphics/png			\
		freetype.9:${PORTSDIR}/print/freetype2		\
		gtkextra.17:${PORTSDIR}/x11-toolkits/gtkextra	\
		gd.4:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2			\
		wget:${PORTSDIR}/ftp/wget

.if !defined(WITHOUT_IODBC)
LIB_DEPENDS+=	iodbc.3:${PORTSDIR}/databases/libiodbc
PLIST_SUB=	ODBC=""
.elseif !defined(WITHOUT_UNIXODBC)
LIB_DEPENDS+=	odbc.1:${PORTSDIR}/databases/unixODBC
PLIST_SUB=	ODBC=""
.else
PLIST_SUB=	ODBC="@comment "
.endif

.if !defined(WITHOUT_MYSQL) || exists(${LOCALBASE}/include/mysql/mysql.h)
USE_MYSQL=	yes
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_PGSQL) || exists(${LOCALBASE}/include/libpq-fe.h)
LIB_DEPENDS+=	pq.3:${PORTSDIR}/${PGSQL_PORT}
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(WITH_FIREBIRD) || exists(${LOCALBASE}/firebird/include/ibase.h)
LIB_DEPENDS+=	gds.1:${PORTSDIR}/${FIREBIRD_PORT}
PLIST_SUB+=	IBASE=""
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
USE_GNOME=		gtk12
HAS_CONFIGURE=		yes
CONFIGURE_WRKSRC=	${WRKSRC}/clip
ALL_TARGET=		local
MAKE_ENV=		HOME=${WRKDIR} LANG=C

PGSQL_PORT?=	databases/postgresql7
FIREBIRD_PORT?=	databases/firebird

BIN2STRIP=	bdbf clip clip_bl clip_blank clip_cld clip_conv clip_dbf2txt	\
		clip_dbg clip_fl clip_hashextract clip_hindex clip_hseek	\
		clip_hv clip_prg clip_run clip_trans clip_we clipar cliphash	\
		codb_ab codb_abx codb_addobj codb_make codb_pack ctosgml dbc	\
		ftosgml gen_tbl po_compat po_extr po_subst pp_ron sqlrun	\
		wcl2prg www_clip xclip

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

do-install:
	${CP} -R ${WRKDIR}/cliproot ${PREFIX}/clip
.for FILE in ${BIN2STRIP}
	@${STRIP_CMD} ${PREFIX}/clip/bin/${FILE}
.endfor
	@for f in `${LS} ${PREFIX}/clip/lib/*.so` ;				\
	do									\
		${STRIP_CMD} $$f ;				\
	done

.include <bsd.port.post.mk>
