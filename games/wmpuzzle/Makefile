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

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN6=		wmpuzzle.6

BSDIMAGES=	daemon.xpm

CPPFLAGS+=	-I${X11BASE}/include 
LDFLAGS+=	-L${X11BASE}/lib

.if !exists(/usr/include/getopt.h)
LIB_DEPENDS+=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
CPPFLAGS+=	-I${LOCALBASE}/include 
LDFLAGS+=	-L${LOCALBASE}/lib -lgnugetopt
.endif

post-extract:
.for i in ${BSDIMAGES}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${i} ${WRKSRC}/
.endfor

.include <bsd.port.mk>
