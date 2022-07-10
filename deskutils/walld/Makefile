PORTNAME= 	walld
DISTVERSION= 	1.4.1
CATEGORIES= 	deskutils

MAINTAINER=	Dotz0cat@gmail.com
COMMENT=	Wallpaper daemon

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libevent.so:devel/libevent \
		libconfig.so:devel/libconfig
RUN_DEPENDS=	feh>0:graphics/feh

USES=	magick meson pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	Dotz0cat

.include <bsd.port.mk>
