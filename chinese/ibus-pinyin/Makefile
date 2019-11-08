# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	ibus-pinyin
PORTVERSION=	1.5.0
PORTREVISION=	9
CATEGORIES=	chinese

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	PinYin engine for IBus

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR} \
		${LOCALBASE}/share/gir-1.0/IBus-1.0.gir:textproc/ibus
LIB_DEPENDS=	libpyzy-1.0.so:chinese/pyzy \
		libibus-1.0.so:textproc/ibus \
		libsqlite3.so:databases/sqlite3

USES=		autoreconf compiler:c++11-lib gettext gmake gnome libtool \
		pkgconfig python
USE_GITHUB=	yes
GH_ACCOUNT=	ibus
USE_GNOME=	glib20 intltool
USE_PYTHON=	py3kplist
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking --disable-lua-extension

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
