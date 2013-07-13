# New ports collection makefile for:	xsynth-dssi
# Date created:		2007-01-20
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	xsynth-dssi
PORTVERSION=	0.9.4
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	SF/dssi/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Classic analog style software synthesizer

BUILD_DEPENDS=	${LOCALBASE}/include/dssi.h:${PORTSDIR}/audio/dssi \
		${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	dssialsacompat.0:${PORTSDIR}/audio/libdssialsacompat \
		lo:${PORTSDIR}/audio/liblo \
		jack.0:${PORTSDIR}/audio/jack

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

USE_GNOME=	gtk20
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
