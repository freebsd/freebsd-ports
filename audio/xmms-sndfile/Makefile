# New ports collection makefile for:	xmms-sndfile
# Date created:				27 Dec 2001
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-sndfile
PORTVERSION=	1.0.p6
CATEGORIES=	audio
MASTER_SITES=	http://www.zipworld.com.au/~erikd/XMMS/
DISTNAME=	xmms_sndfile-${PORTVERSION:S/.p/pre/}

MAINTAINER=	dyeske@yahoo.com

LIB_DEPENDS=	sndfile.0:${PORTSDIR}/audio/libsndfile \
		xmms.3:${PORTSDIR}/audio/xmms

CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"

USE_GLIB=	yes
USE_GTK=	yes
USE_LIBTOOL=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
