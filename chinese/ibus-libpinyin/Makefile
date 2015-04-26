# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	ibus-libpinyin
PORTVERSION=	1.7.1
CATEGORIES=	chinese
MASTER_SITES=	SF/libpinyin/${PORTNAME}

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Intelligent Pinyin engine based on libpinyin for IBus

LICENSE=	GPLv2

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libibus-1.0.so:${PORTSDIR}/textproc/ibus \
		libpinyin.so:${PORTSDIR}/chinese/libpinyin

USES=		compiler:c++11-lib gmake python pkgconfig gettext
USE_GNOME=	glib20

WRKSRC=	${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking --disable-boost \
				--disable-lua-extension

OPTIONS_DEFINE=		ENGLISH STROKE OPENCC NLS
OPTIONS_DEFAULT=	ENGLISH STROKE NLS
ENGLISH_DESC=		Enable English input mode
STROKE_DESC=		Enable stroke input mode
OPENCC_DESC=		Use opencc for simplified and traditional Chinese conversion

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MENGLISH}
CONFIGURE_ARGS+=	--enable-english-input-mode
PLIST_SUB+=	ENGLISH=""
.else
CONFIGURE_ARGS+=	--disable-english-input-mode
PLIST_SUB+=	ENGLISH="@comment "
.endif

.if ${PORT_OPTIONS:MSTROKE}
CONFIGURE_ARGS+=	--enable-stroke-input-mode
PLIST_SUB+=	STROKE=""
.else
CONFIGURE_ARGS+=	--disable-stroke-input-mode
PLIST_SUB+=	STROKE="@comment "
.endif

.if ${PORT_OPTIONS:MOPENCC}
BROKEN=			Requires newer OpenCC
CONFIGURE_ARGS+=	--enable-opencc
LIB_DEPENDS+=		libopencc.so:${PORTSDIR}/chinese/opencc
.else
CONFIGURE_ARGS+=	--disable-opencc
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
USE_GNOME+=	intltool
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|DATADIRNAME = lib|DATADIRNAME = share|' ${WRKSRC}/po/Makefile

.include <bsd.port.post.mk>
