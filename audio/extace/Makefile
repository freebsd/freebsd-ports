# New ports collection makefile for:	extace
# Date created:				8 April 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	extace
PORTVERSION=	1.9.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Audio Visualization plugin for the X Window System

LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw

USE_X_PREFIX=	yes
USE_GNOME=	esound imlib gnomehack gnomeprefix
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-alsa

.include <bsd.port.mk>
