# Created by: Hiroto Kagotani <hiroto.kagotani@gmail.com>
# $FreeBSD$

PORTNAME=	libskk
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://cloud.github.com/downloads/ueno/libskk/

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	Library to deal with Japanese Kana-to-Kanji conversion method

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	gee:${PORTSDIR}/devel/libgee06 \
		json-glib-1.0:${PORTSDIR}/devel/json-glib

USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GCC=	any
USE_GNOME=	intltool gnomehack
USES=		pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	DATADIRNAME=share
MAN1=		skk.1

CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	# Disabling Vala version check
	${REINPLACE_CMD} -e 's/as_fn_error.*Vala.*not found.*;;/;;/' ${WRKSRC}/configure

post-install:
	cd ${WRKSRC}/docs && ${GMAKE} install-man

.include <bsd.port.mk>
