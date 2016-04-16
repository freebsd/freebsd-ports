# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	milkytracker
PORTVERSION=	0.90.86
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.milkytracker.org/files/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Music creation tool inspired by Fast Tracker 2

LICENSE=	GPLv3

NOT_FOR_ARCH=	powerpc

LIB_DEPENDS+=	libjack.so:audio/jack \
		libzzip.so:devel/zziplib

USES=		pkgconfig
GNU_CONFIGURE=	yes
USE_SDL=	sdl

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS+=	--disable-alsatest --without-alsa

PORTDOCS=	FAQ.html MilkyTracker.html ChangeLog.html
ICONS=		carton.ico carton.png

OPTIONS_DEFINE=	DOCS

BROKEN_powerpc64=	Does not build on powerpc64

post-install:
.for f in ${ICONS}
	${INSTALL_DATA} ${WRKSRC}/resources/pictures/${f} \
		${STAGEDIR}${PREFIX}/share/pixmaps/${f:C/carton/milkytracker/}
.endfor
	${INSTALL_DATA} ${WRKSRC}/resources/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
