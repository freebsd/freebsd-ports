# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wmsun
PORTVERSION=	1.05
PORTEPOCH=	1
CATEGORIES=	astro windowmaker
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	mbeis@xs4all.nl
COMMENT=	Dockapp that displays the rise and set times of the Sun

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdockapp.so:x11-wm/libdockapp

USES=		xorg
USE_XORG=	xext xpm x11

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" \
		INCDIR="-I${LOCALBASE}/include" LIBDIR="-L${LOCALBASE}/lib"
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/wmsun man/man1/wmsun.1.gz
WRKSRC=		${WRKDIR}/dockapps-a1e67bd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmsun ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmsun.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
