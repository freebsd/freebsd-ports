# New ports collection makefile for:	chipmunk
# Date created:		29 July 1995
# Whom:			janek@gaja.ipan.lublin.pl
#
# $FreeBSD$
#

PORTNAME=	chipmunk
PORTVERSION=	5.59
CATEGORIES=	cad
MASTER_SITES=	http://www.cs.berkeley.edu/~lazzaro/chipmunk/pickup/sources/
DISTFILES=	psys-1.56.tar.gz log-5.59.tar.gz netcmp-1.12.tar.gz \
		mosis-1.12.tar.gz wol-1.12.tar.gz wolcomp-1.12.tar.gz \
		until-1.12.tar.gz util1.1.tar.gz view-1.12.tar.gz \
		Makefile
EXTRACT_ONLY=	psys-1.56.tar.gz log-5.59.tar.gz netcmp-1.12.tar.gz \
		mosis-1.12.tar.gz wol-1.12.tar.gz wolcomp-1.12.tar.gz \
		until-1.12.tar.gz util1.1.tar.gz view-1.12.tar.gz
DIST_SUBDIR=	chipmunk

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	An electronic CAD system

NO_WRKSUBDIR=	yes
USE_XLIB=	yes
USE_GMAKE=	yes

post-extract:
	@${CP} -f ${DISTDIR}/${DIST_SUBDIR}/Makefile ${WRKSRC}/Makefile

.include <bsd.port.mk>
