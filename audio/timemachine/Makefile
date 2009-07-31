# New ports collection makefile for:	timemachine
# Date created:		2007-01-25
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	timemachine
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://plugin.org.uk/timemachine/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	JACK audio capture tool

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		sndfile.1:${PORTSDIR}/audio/libsndfile

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/liblash.so.2)
LIB_DEPENDS+=	lash.2:${PORTSDIR}/audio/lash
.endif

.include <bsd.port.post.mk>
