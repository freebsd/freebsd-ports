# New ports collection makefile for:	vorbis-tools
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	vorbis-tools
PORTVERSION=	1.0.r2
PORTEPOCH=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.vorbis.com/files/rc2/unix/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	naddy@FreeBSD.org

LIB_DEPENDS=	ao.2:${PORTSDIR}/audio/libao \
		ogg.2:${PORTSDIR}/audio/libogg \
		vorbis.0:${PORTSDIR}/audio/libvorbis

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-ao-prefix=${LOCALBASE} \
		--with-ogg-prefix=${LOCALBASE} \
		--with-vorbis-prefix=${LOCALBASE}

MAN1=		ogg123.1 oggenc.1 ogginfo.1

.include <bsd.port.mk>
