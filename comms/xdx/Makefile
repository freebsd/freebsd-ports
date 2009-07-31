# New ports collection makefile for:	xdx
# Date created:				2004-05-21
# Whom:					Matt Dawson <matt@mattsnetwork.co.uk>
#
# $FreeBSD$
#

PORTNAME=	xdx
PORTVERSION=	2.4
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	http://pg4i.chronos.org.uk/download/ \
		http://www.qsl.net/pg4i/download/

MAINTAINER=	matt@chronos.org.uk
COMMENT=	Amateur Radio DX cluster monitor

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		xdx.1

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g'

.include <bsd.port.mk>
