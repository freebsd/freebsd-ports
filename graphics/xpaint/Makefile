# New ports collection makefile for:	xpaint
# Date created:		2 Jan 1995
# Whom:			swallace
#
# $FreeBSD$
#

PORTNAME=	xpaint
PORTVERSION=	2.6.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.ac-grenoble.fr/Office/
MASTER_SITE_SUBDIR=	sf-${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		xpaint.1

post-patch:
	@${ECHO_CMD} \
		"SYS_LIBRARIES = XawClientLibs -lm" > ${WRKSRC}/Local.xawdefs

.include <bsd.port.mk>
