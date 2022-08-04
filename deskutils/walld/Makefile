PORTNAME=	walld
DISTVERSION=	1.4.4
CATEGORIES=	deskutils

MAINTAINER=	Dotz0cat@gmail.com
COMMENT=	Wallpaper daemon

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libconfig.so:devel/libconfig \
		libevent.so:devel/libevent
RUN_DEPENDS=	feh>0:graphics/feh

USES=		magick meson pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	Dotz0cat

PLIST_FILES=	bin/walld \
		man/man1/walld.1.gz \
		man/man5/walldrc.5.gz

OPTIONS_DEFINE=		XRDB
XRDB_DESC=		Automaticly reload .Xresources with xrdb
XRDB_RUN_DEPENDS=	xrdb>0:X11/xrdb

.include <bsd.port.mk>
