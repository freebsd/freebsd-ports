# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	milkytracker
PORTVERSION=	1.02.00
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	audio

PATCH_SITES=	https://github.com/${PORTNAME}/MilkyTracker/commit/
PATCHFILES=	ba5699e109018d38fd1675c43aef2bab19a880c2.patch:-p1

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Music creation tool inspired by Fast Tracker 2

LICENSE=	GPLv3+ BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING

LIB_DEPENDS=	liblhasa.so:archivers/lhasa \
		libzzip.so:devel/zziplib \
		libjack.so:audio/jack

USES=		cmake compiler:c11 sdl
USE_GITHUB=	yes
USE_SDL=	sdl2

GH_PROJECT=	MilkyTracker

ICONS=		carton.ico carton.png

OPTIONS_DEFINE=	DOCS

post-install:
.for f in ${ICONS}
	${INSTALL_DATA} ${WRKSRC}/resources/pictures/${f} \
		${STAGEDIR}${PREFIX}/share/pixmaps/${f:C/carton/milkytracker/}
.endfor
	${INSTALL_DATA} ${WRKSRC}/resources/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
