# ex:ts=8
# New ports collection makefile for:	darkice
# Date created:			Dec 28, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	darkice
PORTVERSION=	0.7
CATEGORIES=	audio net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	mp3lame:${PORTSDIR}/audio/lame-devel \
		ogg:${PORTSDIR}/audio/libogg \
		vorbis:${PORTSDIR}/audio/libvorbis

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lame-prefix=${LOCALBASE} \
		--with-vorbis-prefix=${LOCALBASE}

MAN1=	darkice.1
MAN5=	darkice.cfg.5

.include <bsd.port.mk>
