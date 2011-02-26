# New ports collection makefile for:	xdx
# Date created:				2004-05-21
# Whom:					Matt Dawson <matt@mattsnetwork.co.uk>
#
# $FreeBSD$
#

PORTNAME=	xdx
PORTVERSION=	2.4
PORTREVISION=	4
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.chronos.org.uk/download/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	matt@chronos.org.uk
COMMENT=	Amateur Radio DX cluster monitor

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		xdx.1
LICENSE=	GPLv2

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED||g'

.include <bsd.port.mk>
