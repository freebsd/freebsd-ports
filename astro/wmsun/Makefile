PORTNAME=	wmsun
DISTVERSION=	1.06
PORTEPOCH=	1
CATEGORIES=	astro windowmaker
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp that displays the rise and set times of the Sun
WWW=		https://www.dockapps.net/wmsun

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdockapp.so:x11-wm/libdockapp

USES=		xorg
USE_XORG=	x11 xext xpm

MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		INCDIR="-I${LOCALBASE}/include" \
		LIBDIR="-L${LOCALBASE}/lib"
MAKE_JOBS_UNSAFE=	yes

#WRKSRC=		${WRKDIR}/dockapps-a1e67bd

PLIST_FILES=	bin/wmsun \
		share/man/man1/wmsun.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmsun ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmsun.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
