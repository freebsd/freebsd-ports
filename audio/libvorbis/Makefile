# New ports collection makefile for:	libvorbis
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	libvorbis
PORTVERSION=	1.0b4
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.vorbis.com/files/beta4/unix/ \
		http://home.student.utwente.nl/t.vanklaveren/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/b/beta/}

MAINTAINER=	naddy@mips.inka.de

LIB_DEPENDS=	ogg.1:${PORTSDIR}/audio/libogg

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-ogg-prefix=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
