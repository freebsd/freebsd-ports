# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	ibus-pinyin
PORTVERSION=	1.5.0
PORTREVISION=	2
CATEGORIES=	chinese
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	PinYin engine for IBus

LICENSE=	GPLv2

BROKEN=		Unfetchable (google code has gone away)

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg \
		${LOCALBASE}/share/gir-1.0/IBus-1.0.gir:textproc/ibus
LIB_DEPENDS=	libpyzy-1.0.so:chinese/pyzy \
		libibus-1.0.so:textproc/ibus \
		libsqlite3.so:databases/sqlite3

USES=		compiler:c++11-lib gmake pkgconfig python
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking --disable-lua-extension

PROJECTHOST=	ibus

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_USE=	GNOME=intltool
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|' ${WRKSRC}/configure

.include <bsd.port.mk>
