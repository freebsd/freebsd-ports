# New ports collection makefile for: icecast
# Date created:         28 Jan 1999
# Whom:                 Chip Marshall <chip@eboai.org>
#
# $FreeBSD$
#

PORTNAME=	icecast2
PORTVERSION=	2.0.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	audio net ipv6
MASTER_SITES=	http://www.icecast.org/files/
DISTNAME=	icecast-${PORTVERSION}

MAINTAINER=	lofi@freebsd.org
COMMENT=	A streaming mp3/ogg-vorbis audio server

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		shout.3:${PORTSDIR}/audio/libshout2 \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		xslt.2:${PORTSDIR}/textproc/libxslt

USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	OGG_PREFIX=${LOCALBASE}

WRKSRC=		${WRKDIR}/icecast-${PORTVERSION}

.include <bsd.port.mk>
