# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	pyzy
PORTVERSION=	0.1.0
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	The Chinese PinYin and Bopomofo conversion library

LICENSE=	LGPL21

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3

USES=		pkgconfig gmake libtool compiler:c++11-lib
USE_GNOME=	glib20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking --disable-boost

OPTIONS_DEFINE=	ANDROID_DB OPENPHRASE_DB OPENCC
OPTIONS_DEFAULT=	ANDROID_DB
ANDROID_DB_DESC=	Build Android DB
OPENPHRASE_DB_DESC=	Build Open Phrase DB
OPENCC_DESC=		Use opencc for simplified and traditional Chinese conversion

.include <bsd.port.options.mk>

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MANDROID_DB}
CONFIGURE_ARGS+=	--enable-db-android
PLIST_SUB+=	ANDROID_DB=""
.else
CONFIGURE_ARGS+=	--disable-db-android
PLIST_SUB+=	ANDROID_DB="@comment "
.endif

OPENPHRASE_DBVER=	1.0.0
OPENPHRASE_DBFILE=	pyzy-database-${OPENPHRASE_DBVER}.tar.bz2

.if ${PORT_OPTIONS:MOPENPHRASE_DB}
CONFIGURE_ARGS+=	--enable-db-open-phrase
DISTFILES+=	${OPENPHRASE_DBFILE}
PLIST_SUB+=	OPENPHRASE_DB=""
.else
CONFIGURE_ARGS+=	--disable-db-open-phrase
PLIST_SUB+=	OPENPHRASE_DB="@comment "
.endif

.if ${PORT_OPTIONS:MOPENCC}
CONFIGURE_ARGS+=	--enable-opencc
LIB_DEPENDS+=		libopencc.so:${PORTSDIR}/chinese/opencc
.else
CONFIGURE_ARGS+=	--disable-opencc
.endif

post-extract:
.if ${PORT_OPTIONS:MOPENPHRASE_DB}
	@${CP} ${DISTDIR}/${OPENPHRASE_DBFILE} ${WRKSRC}/data/db/open-phrase
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' ${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}-1.0.so

.include <bsd.port.post.mk>
