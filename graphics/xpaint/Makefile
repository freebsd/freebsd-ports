# New ports collection makefile for:	xpaint
# Date created:		2 Jan 1995
# Whom:			swallace
#
# $FreeBSD$
#

PORTNAME=	xpaint
PORTVERSION=	2.7.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.ac-grenoble.fr/Office/
MASTER_SITE_SUBDIR=	sf-${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple paint program

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_IMAKE=	yes
USE_XPM=	yes
ALL_TARGET=	xaw95static

MAN1=		xpaint.1

.include <bsd.port.mk>
