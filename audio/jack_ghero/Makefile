# Ports collection makefile for: jack_ghero
# Date created: 21 June 2011
# Whom:         Hans Petter Selasky <hselasky@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jack_ghero
PORTVERSION=	1.0.2
CATEGORIES=	audio
MASTER_SITES=	http://www.selasky.org/hans_petter/distfiles/ \
		http://hselasky.homeunix.org:8192/distfiles/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Daemon that converts a GuitarHero device into a JACK MIDI device

LIB_DEPENDS=	jack.0:${PORTSDIR}/audio/jack

LICENSE=	BSD
USE_BZIP2=	yes
MAKE_JOBS_SAFE=	yes
MANCOMPRESSED=	yes
MAN8=		jack_ghero.8

PLIST_FILES=	sbin/jack_ghero

OPTIONS=	DEBUG "Build with debugging support" Off

.include <bsd.port.options.mk>

MAKE_ARGS+=" HAVE_MAN=YES"

.if defined(WITH_DEBUG)
MAKE_ARGS+=" HAVE_DEBUG=YES"
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=		requires usb stack from FreeBSD 8.0-RELEASE or later
.endif

.include <bsd.port.post.mk>
