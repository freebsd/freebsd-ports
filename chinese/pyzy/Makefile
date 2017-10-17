# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	pyzy
PORTVERSION=	0.1.0
PORTREVISION=	5
CATEGORIES=	chinese

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Chinese PinYin and Bopomofo conversion library

LICENSE=	LGPL21

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

USE_GITHUB=	yes
GH_TAGNAME=	6d9c3cd

USES=		compiler:c++11-lib gmake libtool pkgconfig python:build shebangfix autoreconf gettext-runtime pathfix
SHEBANG_FILES=	data/db/android/create_db.py
USE_GNOME=	glib20
USE_LDCONFIG=	yes

BROKEN_aarch64=		fails to compile: constant expression evaluates to -1
BROKEN_armv6=		fails to compile: constant expression evaluates to -1
BROKEN_powerpc64=	fails to compile: narrowing conversion of '-1' from 'int' to 'char'

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
