# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>

PORTNAME=	mdk
PORTVERSION=	1.3.0
CATEGORIES=	lang gnome
MASTER_SITES=	GNU/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	kfv@kfv.io
COMMENT=	Utilities for developing programs using MIX and MIXAL

LICENSE=	GPLv3

USES=		gettext gmake gnome ncurses pkgconfig readline
USE_GNOME=	glib20 gtk30 intltool
GNU_CONFIGURE=	yes
TEST_TARGET=	check

INFO=		mdk

OPTIONS_DEFINE=	GUILE NLS
OPTIONS_DEFAULT=GUILE
OPTIONS_SUB=	yes

GUILE_CONFIGURE_WITH=	guile
GUILE_LIB_DEPENDS=	libguile-2.2.so:lang/guile2 \
			libgc-threaded.so:devel/boehm-gc-threaded

NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
