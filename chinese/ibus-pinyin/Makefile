# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	ibus-pinyin
PORTVERSION=	1.4.0
PORTREVISION=	2
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	PinYin engine for IBus

BUILD_DEPENDS=	ibus-daemon:${PORTSDIR}/textproc/ibus \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
RUN_DEPENDS=	ibus-daemon:${PORTSDIR}/textproc/ibus \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3

USE_PYTHON=	yes
USE_GNOME=	pygtk2

USE_GCC=	yes
USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking --disable-lua-extension

PROJECTHOST=	ibus

OPTIONS_DEFINE=	ANDROID_DB OPENPHRASE_DB OPENCC NLS
OPTIONS_DEFAULT=	ANDROID_DB
ANDROID_DB_DESC=	Build Android DB
OPENPHRASE_DB_DESC=	Build Open Phrase DB
OPENCC_DESC=		Use opencc

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MANDROID_DB}
CONFIGURE_ARGS+=	--enable-db-android
PLIST_SUB+=	ANDROID_DB=""
.else
CONFIGURE_ARGS+=	--disable-db-android
PLIST_SUB+=	ANDROID_DB="@comment "
.endif

OPENPHRASE_DBVER=	1.2.99
OPENPHRASE_DBFILE=	pinyin-database-${OPENPHRASE_DBVER}.tar.bz2

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
LIB_DEPENDS+=		opencc.1:${PORTSDIR}/chinese/opencc
.else
CONFIGURE_ARGS+=	--disable-opencc
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-extract:
.if ${PORT_OPTIONS:MOPENPHRASE_DB}
	@${CP} ${DISTDIR}/${OPENPHRASE_DBFILE} ${WRKSRC}/data/db/open-phrase
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|' ${WRKSRC}/configure

.include <bsd.port.mk>
