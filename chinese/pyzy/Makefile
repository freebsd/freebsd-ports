# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	pyzy
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	GOOGLE_CODE
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	The Chinese PinYin and Bopomofo conversion library

LICENSE=	LGPL21

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

USES=		compiler:c++11-lib gmake libtool pkgconfig python:build shebangfix
SHEBANG_FILES=	data/db/android/create_db.py
USE_GNOME=	glib20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking --disable-boost

OPTIONS_DEFINE=	ANDROID_DB OPENPHRASE_DB OPENCC
OPTIONS_DEFAULT=	ANDROID_DB
OPTIONS_SUB=	yes
ANDROID_DB_DESC=	Build Android DB
OPENPHRASE_DB_DESC=	Build Open Phrase DB
OPENCC_DESC=		Use opencc for simplified and traditional Chinese conversion

ANDROID_DB_CONFIGURE_ENABLE=	db-android

OPENPHRASE_DBVER=	1.0.0
OPENPHRASE_DBFILE=	pyzy-database-${OPENPHRASE_DBVER}.tar.bz2

OPENPHRASE_DB_CONFIGURE_ENABLE=	db-open-phrase
OPENPHRASE_DB_DISTFILES=	${OPENPHRASE_DBFILE}

OPENCC_CONFIGURE_ENABLE=	opencc
OPENCC_LIB_DEPENDS=		libopencc.so:chinese/opencc

post-extract-OPENPHRASE_DB-on:
	@${CP} ${DISTDIR}/${OPENPHRASE_DBFILE} ${WRKSRC}/data/db/open-phrase

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' ${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}-1.0.so

.include <bsd.port.mk>
