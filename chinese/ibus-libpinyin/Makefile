PORTNAME=	ibus-libpinyin
DISTVERSION=	1.15.2
CATEGORIES=	chinese
MASTER_SITES=	SF/libpinyin/${PORTNAME}

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Intelligent Pinyin engine based on libpinyin for IBus
WWW=		https://github.com/libpinyin/ibus-libpinyin

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3 \
		libibus-1.0.so:textproc/ibus \
		libpinyin.so:chinese/libpinyin

USES=		compiler:c++11-lib gmake gnome python pkgconfig gettext
USE_GNOME=	glib20
GLIB_SCHEMAS=	com.github.libpinyin.ibus-libpinyin.gschema.xml

WRKSRC=	${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking --disable-boost \
				--disable-lua-extension

OPTIONS_DEFINE=		ENGLISH TABLE OPENCC NLS
OPTIONS_DEFAULT=	ENGLISH TABLE OPENCC
OPTIONS_SUB=		yes
ENGLISH_DESC=		Enable English input mode
TABLE_DESC=		Enable table input mode
OPENCC_DESC=		Use opencc for simplified and traditional Chinese conversion

ENGLISH_CONFIGURE_ENABLE=	english-input-mode
TABLE_CONFIGURE_ENABLE=		table-input-mode

OPENCC_CONFIGURE_ENABLE=	opencc
OPENCC_LIB_DEPENDS=		libopencc.so:chinese/opencc

NLS_USES=		gettext
NLS_USE=		GNOME=intltool
NLS_CONFIGURE_ENABLE=	nls

post-configure:
	@${REINPLACE_CMD} -e 's|DATADIRNAME = lib|DATADIRNAME = share|' ${WRKSRC}/po/Makefile

.include <bsd.port.mk>
