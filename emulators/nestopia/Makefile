# $FreeBSD$

PORTNAME=	nestopia
PORTVERSION=	1.47
CATEGORIES=	emulators

MAINTAINER=	neel@neelc.org
COMMENT=	Portable NES/Famicom emulator

LICENSE=	GPLv2

LIB_DEPENDS=	libao.so:audio/libao

USES=		gmake libarchive pkgconfig
USE_GL=		glu
USE_GNOME=	gtk30
USE_SDL=	sdl2

USE_GITHUB=	yes
GH_ACCOUNT=	rdanbrook

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
