# New ports collection makefile for:	vorbis
# Date created:				22 August 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	vorbis
PORTVERSION=	1.0.r2
PORTEPOCH=	2
CATEGORIES=	audio
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	naddy@FreeBSD.org

LIB_DEPENDS=	ao.2:${PORTSDIR}/audio/libao \
		ogg.2:${PORTSDIR}/audio/libogg \
		vorbis.0:${PORTSDIR}/audio/libvorbis
RUN_DEPENDS=	ogg123:${PORTSDIR}/audio/vorbis-tools

MD5_FILE=	Makefile	# dummy
NO_BUILD=	yes
PLIST=		${WRKDIR}/pkg-plist
SUBPORTS=	libao libogg libvorbis vorbis-tools

pre-install:
		@${ECHO} "@comment intentionally left empty" > ${PLIST}

do-install:	# empty

.include <bsd.port.mk>
