# New ports collection makefile for:	chipmunk
# Date created:		29 July 1995
# Whom:			janek@gaja.ipan.lublin.pl
#
# $FreeBSD$
#

PORTNAME=	chipmunk
PORTVERSION=	5.64
CATEGORIES=	cad
MASTER_SITES=	http://www.cs.berkeley.edu/~lazzaro/chipmunk/pickup/sources/
DISTFILES=	psys-1.59.tar.gz log-5.64.tar.gz netcmp-1.13.tar.gz \
		mosis-1.14.tar.gz wol-1.14.tar.gz wolcomp-1.14.tar.gz \
		until-1.14.tar.gz util-1.11.tar.gz view-1.14.tar.gz \
		Makefile
DIST_SUBDIR=	chipmunk
EXTRACT_ONLY=	psys-1.59.tar.gz log-5.64.tar.gz netcmp-1.13.tar.gz \
		mosis-1.14.tar.gz wol-1.14.tar.gz wolcomp-1.14.tar.gz \
		until-1.14.tar.gz util-1.11.tar.gz view-1.14.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An electronic CAD system

NO_WRKSUBDIR=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Broken pkg-plist on alpha"
.endif

post-extract:
	@${CP} -f ${DISTDIR}/${DIST_SUBDIR}/Makefile ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
