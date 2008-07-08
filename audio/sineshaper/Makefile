# New ports collection makefile for:	sineshaper
# Date created:		2008-05-16
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sineshaper
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://ll-plugins.sourceforge.net/release/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Monophonic synth plugin with two oscillators and waveshapers

LIB_DEPENDS=	dssialsacompat.0:${PORTSDIR}/audio/libdssialsacompat \
		lo.6:${PORTSDIR}/audio/liblo \
		jack.0:${PORTSDIR}/audio/jack \
		glademm-2.4:${PORTSDIR}/devel/libglademm24
BUILD_DEPENDS=	${LOCALBASE}/include/dssi.h:${PORTSDIR}/audio/dssi

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GCC=	4.2+
CFLAGS+=	-I${LOCALBASE}/include/dssi
USE_AUTOTOOLS=	autoconf:261 automake:110:env libtool:15

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile
.endif

pre-configure:
	cd ${WRKSRC} && ${AUTORECONF}

.include <bsd.port.post.mk>
