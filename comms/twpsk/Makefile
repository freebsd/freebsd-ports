# New ports collection makefile for:    twpsk
# Date created:         2005-05-27
# Whom:                 Søren Straarup <xride@x12.dk>
#
# $FreeBSD$
#

PORTNAME=	twpsk
PORTVERSION=	2.1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.ibiblio.org/pub/linux/apps/ham/

MAINTAINER=	xride@x12.dk
COMMENT=	A openmotif X psk31 client

USE_XPM=	yes
USE_MOTIF=	yes

MAN1=		psk31.1

FILES_TO_PATCH=	Makefile psk31.1 twpskHelp
post-patch:
.for file in ${FILES_TO_PATCH}
	@${REINPLACE_CMD} -e \
		's|/usr/local|${LOCALBASE}|g;s|/usr/X11R6|${X11BASE}|g' \
		${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
