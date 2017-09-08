# $FreeBSD$

PORTNAME=	nestopia
PORTVERSION=	1.48
CATEGORIES=	emulators

MAINTAINER=	neel@neelc.org
COMMENT=	Portable NES/Famicom emulator

LICENSE=	GPLv2

LIB_DEPENDS=	libao.so:audio/libao libepoxy.so:graphics/libepoxy

USES=		cmake desktop-file-utils libarchive localbase:ldflags pkgconfig
USE_GL=		glu
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	rdanbrook

INSTALLS_ICONS=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
