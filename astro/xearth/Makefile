# New ports collection makefile for:    xearth
# Date created:         29 October 1994
# Whom:                 piero
#
# $FreeBSD$
#

PORTNAME=	xearth
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	astro geography
MASTER_SITES=	ftp://cag.lcs.mit.edu/pub/tuna/ \
		${MASTER_SITE_XCONTRIB:S/$/:xcontrib/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	applications/:xcontrib simon/:local
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:xcontrib,local

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set the root window to the image of earth

USE_IMAKE=	yes

MAN1=		xearth.1

# Copy the list of FreeBSD sites & committers locations
post-install:
	@${MKDIR} ${PREFIX}/lib/X11/xearth
.for marker in freebsd.committers.markers freebsd.submitters.markers freebsd.ftp.markers
	@${INSTALL_DATA} ${FILESDIR}/${marker} ${PREFIX}/lib/X11/xearth
.endfor

.include <bsd.port.mk>
