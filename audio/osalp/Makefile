# ex:ts=8
# Ports collection makefile for:	osalp
# Date created:			Jun 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	osalp
PORTVERSION=	0.7.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Open Source Audio Library Project

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123
LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
    		vorbis.4:${PORTSDIR}/audio/libvorbis

GNU_CONFIGURE=	yes
CFLAGS+=	-fPIC -DPIC
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-all

USE_LDCONFIG=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

CONFLICTS=	libaudiofile-[0-9]*

.include <bsd.port.mk>
