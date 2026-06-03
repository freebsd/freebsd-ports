PORTNAME=	ibus-skk
DISTVERSIONPREFIX=	ibus-skk-
DISTVERSION=	1.4.4
CATEGORIES=	japanese

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Japanese SKK input engine for IBus
WWW=		https://github.com/ueno/ibus-skk

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libibus-1.0.so:textproc/ibus \
		libskk.so:japanese/libskk
RUN_DEPENDS=	${LOCALBASE}/share/skk/SKK-JISYO.L:japanese/skk-jisyo

USES=		autoreconf gettext-tools gmake gnome libtool pkgconfig \
		vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	ueno
USE_GNOME=	glib20 gtk30 intltool

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime

post-patch:
	@${REINPLACE_CMD} -e '/SKK-JISYO/s,/usr/share,${LOCALBASE}/share,' \
		${WRKSRC}/src/preferences.vala

.include <bsd.port.mk>
