# New ports collection makefile for:	wmpuzzle
# Date created:			15 May 2002
# Whom:				Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmpuzzle
PORTVERSION=	0.2.0
CATEGORIES=	games windowmaker afterstep
MASTER_SITES=	http://www.godisch.de/debian/wmpuzzle/ \
		${MASTER_SITE_LOCAL:S/$/:bsdpics/}
MASTER_SITE_SUBDIR=	petef/:bsdpics
DISTFILES=	wmpuzzle_${PORTVERSION}.orig${EXTRACT_SUFX} \
		daemon.xpm:bsdpics
DIST_SUBDIR=	wmpuzzle
EXTRACT_ONLY=	wmpuzzle_${PORTVERSION}.orig${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lgnugetopt"
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
USE_X_PREFIX=	yes
USE_XPM=	yes

MAN6=		wmpuzzle.6

BSDIMAGES=	daemon.xpm

post-extract:
.for i in ${BSDIMAGES}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/$i ${WRKSRC}/
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmpuzzle ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmpuzzle.6 ${PREFIX}/man/man6

.include <bsd.port.mk>
