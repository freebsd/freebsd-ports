# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	ibus-pinyin
PORTVERSION=	1.5.0
PORTREVISION=	3
CATEGORIES=	chinese

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	PinYin engine for IBus

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg \
		${LOCALBASE}/share/gir-1.0/IBus-1.0.gir:textproc/ibus
LIB_DEPENDS=	libpyzy-1.0.so:chinese/pyzy \
		libibus-1.0.so:textproc/ibus \
		libsqlite3.so:databases/sqlite3

USES=		compiler:c++11-lib gmake pkgconfig python autoreconf libtool
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking --disable-lua-extension

USE_GITHUB=	yes
GH_ACCOUNT=	ibus

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_USE=	GNOME=intltool
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
