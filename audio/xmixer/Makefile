# New ports collection makefile for:	xmixer
# Date created:		27 October 1999
# Whom:			Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	xmixer
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	audio
# Master site seems to be MIA and no replacement could be found
MASTER_SITES=	#http://www.hdk-berlin.de/~rasca/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio mixer (gtk and Xlib) for X11R6

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_REINPLACE=	yes
USE_GNOME=	gtk12
USE_AUTOCONF=	yes

MAN1=		xmixer.1
MLINKS=		xmixer.1 xgmixer.1

pre-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS}  ${REINPLACE_CMD} -e 's|rxvt -e|xterm -e|g'

.include <bsd.port.mk>
