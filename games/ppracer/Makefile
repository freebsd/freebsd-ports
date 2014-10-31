# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ppracer
DISTVERSION=	0.5alpha
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	BERLIOS \
		SF/${PORTNAME}.berlios/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D downhill racing game... kind of like TuxRacer Improved

LICENSE=	GPLv2

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2

USES=		gmake pkgconfig dos2unix desktop-file-utils tar:bzip2
DOS2UNIX_REGEX=	.*\.(c|cpp|h)
USE_SDL=	mixer sdl
USE_GL=		gl
USE_XORG=	x11 xi xext xmu xt
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog ChangeLog-pre0.3.9 ChangeLog-tuxracer
OPTIONS_DEFINE= DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		-e 's|libpng12|libpng15|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|RacingMode::||' ${WRKSRC}/src/racingmode.h
	@${REINPLACE_CMD} -e 's|int SQHash|long SQHash|' \
		${WRKSRC}/src/squirrel/squirrel.h

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
