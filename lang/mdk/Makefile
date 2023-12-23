PORTNAME=	mdk
PORTVERSION=	1.3.0
PORTREVISION=	3
CATEGORIES=	lang gnome
MASTER_SITES=	GNU/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	antranigv@freebsd.am
COMMENT=	Utilities for developing programs using MIX and MIXAL
WWW=		https://www.gnu.org/software/mdk/mdk.html

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
GUILE_USES=	guile:2.2,conflicts

NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
