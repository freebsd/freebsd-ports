# New ports collection makefile for:    xasteroids
# Date created:         3 Jan 1995
# Whom:                 swallace
#
# $FreeBSD$
#

PORTNAME=	xasteroids
PORTVERSION=	5.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cdrom.com/pub/X11/R5contrib/ \
		ftp://ftp.belgium.eu.net/pub/X11/R5contrib/
DISTFILES=       xasteroids.sh.Z

MAINTAINER=	swallace@FreeBSD.org

USE_IMAKE=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	( cd ${WRKDIR}; zcat | sh -s )
EXTRACT_BEFORE_ARGS=	<
EXTRACT_AFTER_ARGS=	# empty
MAN6=		xasteroids.6

.include <bsd.port.mk>
