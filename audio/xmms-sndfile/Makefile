# New ports collection makefile for:	xmms-sndfile
# Date created:				27 Dec 2001
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-sndfile
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.zipworld.com.au/~erikd/XMMS/
DISTNAME=	xmms_sndfile-${PORTVERSION}

MAINTAINER=	dyeske@yahoo.com
COMMENT=	XMMS plugin to allow playing libsndfile supported files

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile \
		xmms.4:${PORTSDIR}/multimedia/xmms

CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"

USE_GNOME=	gtk12
USE_LIBTOOL=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
