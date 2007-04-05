# New ports collection makefile for:	twolame
# Date created:		2005-05-02
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	twolame
PORTVERSION=	0.3.10
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.ecs.soton.ac.uk/~njh/twolame/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	MPEG Audio Layer 2 encoder

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile

USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/man

MAN1=		twolame.1

post-patch:
	@${REINPLACE_CMD} -e 's| -O3||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
