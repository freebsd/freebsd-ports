# Created by: Henry Hu <henry.hu.sh@gmail.com>
# $FreeBSD$

PORTNAME=	ibus-pinyin
PORTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	PinYin engine for IBus

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xdg>0:${PORTSDIR}/devel/py-xdg \
		${LOCALBASE}/share/gir-1.0/IBus-1.0.gir:${PORTSDIR}/textproc/ibus
LIB_DEPENDS=	libpyzy-1.0.so:${PORTSDIR}/chinese/pyzy \
		libibus-1.0.so:${PORTSDIR}/textproc/ibus \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3

USE_PYTHON=	yes

USES=		gmake pkgconfig compiler:c++11-lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking --disable-lua-extension

PROJECTHOST=	ibus

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
USE_GNOME+=	intltool
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|' ${WRKSRC}/configure

.include <bsd.port.mk>
