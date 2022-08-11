PORTNAME=	milkytracker
PORTVERSION=	1.03.00
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Music creation tool inspired by Fast Tracker 2

LICENSE=	GPLv3+ BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING

LIB_DEPENDS=	liblhasa.so:archivers/lhasa \
		libzzip.so:devel/zziplib \
		libjack.so:audio/jack

USES=		cmake compiler:c11 cpe sdl
USE_GITHUB=	yes
USE_SDL=	sdl2

CPE_VENDOR=	milkytracker_project

GH_PROJECT=	MilkyTracker

ICONS=		carton.ico carton.png

OPTIONS_DEFINE=	DOCS

# ci pipeline creates transient tags
PORTSCOUT=	ignore:1

post-install:
.for f in ${ICONS}
	${INSTALL_DATA} ${WRKSRC}/resources/pictures/${f} \
		${STAGEDIR}${PREFIX}/share/pixmaps/${f:C/carton/milkytracker/}
.endfor
	${INSTALL_DATA} ${WRKSRC}/resources/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
