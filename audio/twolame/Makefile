# New ports collection makefile for:	twolame
# Date created:		2005-05-02
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	twolame
PORTVERSION=	0.3.13
CATEGORIES=	audio
MASTER_SITES=	SF \
		http://www.ecs.soton.ac.uk/~njh/twolame/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	MPEG Audio Layer 2 encoder

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile

USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

MAN1=		twolame.1

post-patch:
	@${REINPLACE_CMD} -e 's| -O3||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
