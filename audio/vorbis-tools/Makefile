# New ports collection makefile for:	vorbis-tools
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	vorbis-tools
PORTVERSION=	1.0.r3
PORTEPOCH=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.xiph.org/ogg/vorbis/download/ \
		http://www.vorbis.com/files/rc3/unix/ \
		http://www.oddsock.org/vorbisrc3/files/rc3/unix/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	naddy@FreeBSD.org

LIB_DEPENDS=	ao.3:${PORTSDIR}/audio/libao \
		ogg.3:${PORTSDIR}/audio/libogg \
		vorbis.1:${PORTSDIR}/audio/libvorbis \
		curl.2:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ao=${LOCALBASE} \
		--with-ogg=${LOCALBASE} \
		--with-vorbis=${LOCALBASE} \
		--with-curl=${LOCALBASE}

MAN1=		ogg123.1 oggenc.1 ogginfo.1 vcut.1 vorbiscomment.1

.include <bsd.port.mk>
