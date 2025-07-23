PORTNAME=	pyzy
PORTVERSION=	0.1.0
PORTREVISION=	9
CATEGORIES=	chinese

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Chinese PinYin and Bopomofo conversion library
WWW=		https://github.com/pyzy/pyzy

LICENSE=	LGPL21

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

USES=		autoreconf compiler:c++11-lang gettext-runtime gmake gnome \
		libtool pkgconfig python:build shebangfix
SHEBANG_FILES=	data/db/android/create_db.py
USE_GITHUB=	yes
GH_TAGNAME=	6d9c3cd
USE_GNOME=	glib20
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking --disable-boost

OPTIONS_DEFINE=	OPENCC
OPTIONS_DEFAULT=
OPTIONS_SUB=	yes
OPENCC_DESC=	Use opencc for simplified and traditional Chinese conversion

OPENCC_CONFIGURE_ENABLE=	opencc
OPENCC_LIB_DEPENDS=		libopencc.so:chinese/opencc

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}-1.0.so

.include <bsd.port.mk>
