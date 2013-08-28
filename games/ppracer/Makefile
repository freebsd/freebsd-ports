# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ppracer
DISTVERSION=	0.5alpha
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D downhill racing game... kind of like TuxRacer Improved

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_SDL=	mixer sdl
USE_GL=		gl
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(c|cpp|h)
USE_XORG=	x11 xi xext xmu xt

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' \
		-e 's,libpng12,libpng15,g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,RacingMode::,,' ${WRKSRC}/src/racingmode.h

.include <bsd.port.mk>
