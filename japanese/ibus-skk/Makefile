# Created by: Hiroto Kagotani <hiroto.kagotani@gmail.com>
# $FreeBSD$

PORTNAME=	ibus-skk
DISTVERSIONPREFIX=	ibus-skk-
DISTVERSION=	1.4.3
CATEGORIES=	japanese

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese SKK input engine for IBus

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
RUN_DEPENDS=	${LOCALBASE}/share/skk/SKK-JISYO.L:japanese/skk-jisyo
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libibus-1.0.so:textproc/ibus \
		libskk.so:japanese/libskk

USES=		autoreconf gettext gmake gnome libtool pkgconfig python
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	DATADIRNAME=share
USE_GITHUB=	yes
GH_ACCOUNT=	ueno
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 intltool pango

CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	NLS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/skk/SKK-JISYO.L|${LOCALBASE}/share/skk/SKK-JISYO.L|' ${WRKSRC}/src/preferences.vala

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.post.mk>
