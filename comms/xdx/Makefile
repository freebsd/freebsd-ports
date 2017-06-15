# Created by: Matt Dawson <matt@mattsnetwork.co.uk>
# $FreeBSD$

PORTNAME=	xdx
PORTVERSION=	2.4
PORTREVISION=	6
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.chronos.org.uk/download/ \
		LOCAL/db

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Amateur Radio DX cluster monitor

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig

LICENSE=	GPLv2

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g'

.include <bsd.port.mk>
