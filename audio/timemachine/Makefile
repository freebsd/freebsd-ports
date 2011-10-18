# New ports collection makefile for:	timemachine
# Date created:		2007-01-25
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	timemachine
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://plugin.org.uk/timemachine/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JACK audio capture tool

LICENSE=	GPLv2

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack \
		lo.7:${PORTSDIR}/audio/liblo \
		sndfile.1:${PORTSDIR}/audio/libsndfile

OPTIONS=	LASH "Enable LASH support" off

USE_GNOME=	gnomehack gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.options.mk>

.if defined(WITH_LASH)
LIB_DEPENDS+=	lash.2:${PORTSDIR}/audio/lash
.else
CONFIGURE_ARGS+=--disable-lash
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^PACKAGE_CFLAGS=/s|-g||; \
		 /^PACKAGE_LIBS=/s|-g||' ${WRKSRC}/configure

.include <bsd.port.mk>
