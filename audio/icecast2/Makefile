# New ports collection makefile for: icecast
# Date created:         28 Jan 1999
# Whom:                 Chip Marshall <chip@eboai.org>
#
# $FreeBSD$
#

PORTNAME=	icecast2
PORTVERSION=	2.0.a.2.20030811
PORTEPOCH=	1
CATEGORIES=	audio net ipv6
MASTER_SITES=	http://tigress.com/lofi/\
		http://lofi.dyndns.org/
DISTNAME=	icecast-2.0-alpha-2-20030811

MAINTAINER=	lofi@freebsd.org
COMMENT=	A streaming mp3/ogg-vorbis audio server

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		ogg.4:${PORTSDIR}/audio/libogg \
		shout.3:${PORTSDIR}/audio/libshout2 \
		vorbis.2:${PORTSDIR}/audio/libvorbis \
		xslt.1:${PORTSDIR}/textproc/libxslt

USE_GMAKE=	yes
USE_LIBTOOL=	yes

WRKSRC=		${WRKDIR}/icecast-2.0-alpha-2

.include <bsd.port.mk>
