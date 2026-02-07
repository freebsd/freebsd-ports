PORTNAME=	xiccd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
CATEGORIES=	graphics x11

MAINTAINER=	ports@zoltankiraly.com
COMMENT=	X color profile daemon

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcolord.so:graphics/colord \
		libglib-2.0.so:devel/glib20 \
		libintl.so:devel/gettext-runtime

USES=		autoreconf pkgconfig xorg
USE_XORG=	x11 xrandr

USE_GITHUB=	yes
GH_ACCOUNT=	agalakhov

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/xiccd \
		share/man/man8/xiccd.8.gz \
		etc/xdg/autostart/xiccd.desktop

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
