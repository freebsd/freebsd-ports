# New ports collection makefile for:    xchomp
# Version required:     pl1
# Date created:         4 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.6 1996/11/18 11:25:21 asami Exp $
#

DISTNAME=       xchomp-pl1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.uoknor.edu/mirrors/X/R5contrib/ \
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	../../R5contrib
#
# Original sources in multi-part compressed shell archive
#
#DISTFILES=	part01.Z part02.Z part03.Z part04.Z part05.Z patch1.Z
#MASTER_SITES=	ftp://ftp.wustl.edu/usenet/comp.sources.x/volume06

MAINTAINER=	swallace@FreeBSD.org

WRKSRC=		${WRKDIR}/xchomp
USE_IMAKE=	yes
NO_INSTALL_MANPAGES= yes

# Change -DFRAME_DELAY=40000 in patchfile/Imakefile value to adjust
# speed of play depending on X server.

.include <bsd.port.mk>
