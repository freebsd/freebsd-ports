# New ports collection makefile for:   xtide
# Version required:    1.6.2
# Date created:        30 August 1997
# Whom:                Brion Moss <brion@queeg.com>
#
# $FreeBSD$
#

DISTNAME=	xtide-1.6.2
CATEGORIES=	astro
MASTER_SITES=	http://www.universe.digex.net/~dave/files/
DISTFILES=	xtide-1.6.2.tar.gz harmonics.gz

MAINTAINER=	brion@queeg.com

# www.universe.digex.net is broken
FETCH_BEFORE_ARGS=	-t

EXTRACT_ONLY=	xtide-1.6.2.tar.gz
USE_IMAKE=	yes
NO_WRKSUBDIR=	yes
MAN1=		xtide.1
MANCOMPRESSED=	no

post-extract:
	@${GZCAT} ${DISTDIR}/harmonics.gz > ${WRKSRC}/harmonics

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtide ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xtide.man ${PREFIX}/man/man1/xtide.1
	@${MKDIR} ${PREFIX}/lib/xtide
	${INSTALL_DATA} ${WRKSRC}/harmonics ${PREFIX}/lib/xtide

.include <bsd.port.mk>
