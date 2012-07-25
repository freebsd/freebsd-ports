# New ports collection makefile for:	zh-ibus-pinyin
# Date created:				21 October 2008
# Whom:					Henry Hu <henry.hu.sh@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ibus-pinyin
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	PinYin engine for IBus

BUILD_DEPENDS=	ibus-daemon:${PORTSDIR}/textproc/ibus \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3
RUN_DEPENDS=	ibus-daemon:${PORTSDIR}/textproc/ibus \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3

USE_PYTHON=	yes
USE_GNOME=	pygtk2

USE_GCC=	4.6+
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking --disable-lua-extension

PROJECTHOST=	ibus

OPTIONS=	ANDROID_DB	"Build Android DB" on \
			OPENPHRASE_DB	"Build Open Phrase DB" off \
			OPENCC	"Use opencc" off

.include <bsd.port.pre.mk>

.if defined(WITH_ANDROID_DB)
CONFIGURE_ARGS+=	--enable-db-android
PLIST_SUB+=	ANDROID_DB=""
.else
CONFIGURE_ARGS+=	--disable-db-android
PLIST_SUB+=	ANDROID_DB="@comment "
.endif

OPENPHRASE_DBVER=	1.2.99
OPENPHRASE_DBFILE=	pinyin-database-${OPENPHRASE_DBVER}.tar.bz2

.if defined(WITH_OPENPHRASE_DB)
CONFIGURE_ARGS+=	--enable-db-open-phrase
DISTFILES+=	${OPENPHRASE_DBFILE}
PLIST_SUB+=	OPENPHRASE_DB=""
.else
CONFIGURE_ARGS+=	--disable-db-open-phrase
PLIST_SUB+=	OPENPHRASE_DB="@comment "
.endif

.if defined(WITH_OPENCC)
CONFIGURE_ARGS+=	--enable-opencc
LIB_DEPENDS+=		opencc.1:${PORTSDIR}/chinese/opencc
.else
CONFIGURE_ARGS+=	--disable-opencc
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-extract:
.if defined(WITH_OPENPHRASE_DB)
	@${CP} ${DISTDIR}/${OPENPHRASE_DBFILE} ${WRKSRC}/data/db/open-phrase
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|' ${WRKSRC}/configure

.include <bsd.port.post.mk>
