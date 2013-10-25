# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmsun
PORTVERSION=	1.03
PORTREVISION=	2
CATEGORIES=	astro windowmaker
MASTER_SITES=	http://dockapps.windowmaker.org/download.php/id/23/
DISTNAME=	wmSun-1.03

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp that displays the rise and set times of the Sun

FETCH_ARGS=	-Fpr

WRKSRC=		${WRKDIR}/${DISTNAME}/wmSun

USE_XORG=	xext xpm x11
ALL_TARGET=	clean all
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" \
		INCDIR="-I${LOCALBASE}/include" LIBDIR="-L${LOCALBASE}/lib"
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/wmSun man/man1/wmSun.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmSun ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmSun.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
