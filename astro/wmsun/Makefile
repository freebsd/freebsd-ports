# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmsun
PORTVERSION=	1.12
CATEGORIES=	astro windowmaker
MASTER_SITES=	http://linux-bsd-unix.strefa.pl/
DISTNAME=	wmSun-${PORTVERSION}

MAINTAINER=	mbeis@xs4all.nl
COMMENT=	Dockapp that displays the rise and set times of the Sun

WRKSRC_SUBDIR=	wmSun

USE_XORG=	xext xpm x11
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" \
		INCDIR="-I${LOCALBASE}/include" LIBDIR="-L${LOCALBASE}/lib"
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/wmSun man/man1/wmSun.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmSun ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmSun.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
