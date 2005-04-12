# ex:ts=8
# Ports collection makefile for:	osalp
# Date created:			Jun 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	osalp
PORTVERSION=	0.7.3
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source Audio Library Project

BUILD_DEPENDS=	lame:${PORTSDIR}/audio/lame \
		mpg123:${PORTSDIR}/audio/mpg123
LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CFLAGS+=	-fPIC -DPIC
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-all

INSTALLS_SHLIB=	yes

PLIST_SUB=	VERSION=${PORTVERSION}

CONFLICTS=	libaudiofile-*

.include <bsd.port.mk>
