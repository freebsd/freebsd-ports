# New ports collection makefile for:	chipmunk
# Date created:		29 July 1995
# Whom:			janek@gaja.ipan.lublin.pl
#
# $FreeBSD$
#

PORTNAME=	chipmunk
PORTVERSION=	5.62
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.cs.berkeley.edu/~lazzaro/chipmunk/pickup/sources/
DISTFILES=	psys-1.58.tar.gz log-5.62.tar.gz netcmp-1.13.tar.gz \
		mosis-1.14.tar.gz wol-1.14.tar.gz wolcomp-1.14.tar.gz \
		until-1.14.tar.gz util-1.11.tar.gz view-1.14.tar.gz \
		Makefile
EXTRACT_ONLY=	psys-1.58.tar.gz log-5.62.tar.gz netcmp-1.13.tar.gz \
		mosis-1.14.tar.gz wol-1.14.tar.gz wolcomp-1.14.tar.gz \
		until-1.14.tar.gz util-1.11.tar.gz view-1.14.tar.gz
DIST_SUBDIR=	chipmunk

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An electronic CAD system

NO_WRKSUBDIR=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

post-extract:
	@${CP} -f ${DISTDIR}/${DIST_SUBDIR}/Makefile ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
