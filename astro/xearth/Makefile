# New ports collection makefile for:    xearth
# Date created:         29 October 1995
# Whom:                 piero
#
# $FreeBSD$
#

PORTNAME=	xearth
PORTVERSION=	1.1
CATEGORIES=	astro x11
MASTER_SITES=	ftp://cag.lcs.mit.edu/pub/tuna/ \
		ftp://ftp.cs.colorado.edu/users/tuna/ \
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR= applications

MAINTAINER=	ports@FreeBSD.org

USE_IMAKE=	yes

MAN1=		xearth.1

# Copy the list of FreeBSD sites
post-install:
	${MKDIR} ${PREFIX}/lib/X11/xearth
	${CP} ${FILESDIR}/freebsd.core.markers ${PREFIX}/lib/X11/xearth
	${CP} ${FILESDIR}/freebsd.committers.markers ${PREFIX}/lib/X11/xearth
	${CP} ${FILESDIR}/freebsd.ftp.markers ${PREFIX}/lib/X11/xearth
	${ECHO} "# All of FreeBSD's committers, including core :)" > \
	    ${PREFIX}/lib/X11/xearth/freebsd.core_and_committers.markers
	${GREP} -hv '^[[:space:]]*#' ${FILESDIR}/freebsd.core.markers \
	    ${FILESDIR}/freebsd.committers.markers >> \
	    ${PREFIX}/lib/X11/xearth/freebsd.core_and_committers.markers

.include <bsd.port.mk>
