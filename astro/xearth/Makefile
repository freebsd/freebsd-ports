# New ports collection makefile for:    xearth
# Date created:         29 October 1994
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

# Always prep the joint marker list for every new install
pre-install:
	@${ECHO} "# All of FreeBSD's committers, including core :)" > \
		${WRKDIR}/freebsd.core_and_committers.markers
	@${GREP} -hv '^[[:space:]]*#' ${FILESDIR}/freebsd.core.markers \
	    ${FILESDIR}/freebsd.committers.markers >> \
		${WRKDIR}/freebsd.core_and_committers.markers

# Copy the list of FreeBSD sites
post-install:
	@${MKDIR} ${PREFIX}/lib/X11/xearth
.for file in freebsd.core.markers freebsd.committers.markers \
	freebsd.ftp.markers
	@${INSTALL_DATA} ${FILESDIR}/${file} ${PREFIX}/lib/X11/xearth
.endfor
	@${INSTALL_DATA} \
		${WRKDIR}/freebsd.core_and_committers.markers \
			${PREFIX}/lib/X11/xearth

.include <bsd.port.mk>
