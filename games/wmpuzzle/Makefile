# New ports collection makefile for:	wmpuzzle
# Date created:			15 May 2002
# Whom:				Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	wmpuzzle
PORTVERSION=	0.1.1
CATEGORIES=	games windowmaker afterstep
MASTER_SITES=	http://wwwtcs.inf.tu-dresden.de/~godisch/debian/wmpuzzle/ \
		${MASTER_SITE_LOCAL:S/$/:bsdpics/}
MASTER_SITE_SUBDIR=	petef/:bsdpics
DISTFILES=	wmpuzzle_${PORTVERSION}.orig${EXTRACT_SUFX} \
		daemon.gif:bsdpics daemon.xpm:bsdpics
DIST_SUBDIR=	wmpuzzle
EXTRACT_ONLY=	wmpuzzle_${PORTVERSION}.orig${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
USE_X_PREFIX=	yes
USE_XPM=	yes

MAN6=		wmpuzzle.6

BSDIMAGES=	daemon.gif daemon.xpm

post-extract:
.for i in ${BSDIMAGES}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/$i ${WRKSRC}/xpm
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmpuzzle ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmpuzzle.6 ${PREFIX}/man/man6

.include <bsd.port.mk>
