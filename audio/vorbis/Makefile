# New ports collection makefile for:	vorbis
# Date created:				22 August 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	vorbis
PORTVERSION=	20001018
CATEGORIES=	audio
MASTER_SITES=	# empty
DISTFILES=	# none
EXTRACT_ONLY=	# empty

MAINTAINER=	t.vanklaveren@student.utwente.nl

LIB_DEPENDS=	ao.0:${PORTSDIR}/audio/libao \
		ogg.0:${PORTSDIR}/audio/libogg \
		vorbis.0:${PORTSDIR}/audio/libvorbis
RUN_DEPENDS=	${X11BASE}/lib/xmms/Input/libvorbis.so:${PORTSDIR}/audio/vorbis-xmms \
		ogg123:${PORTSDIR}/audio/vorbis-tools

MD5_FILE=	Makefile	# dummy
NO_BUILD=	yes
PLIST=		${WRKDIR}/pkg-plist
SUBPORTS=	libao libogg libvorbis vorbis-tools vorbis-xmms

pre-install:
		${ECHO} "@comment intentionally left empty" > ${PLIST}

do-install:	# empty

do-package:
.for i in ${SUBPORTS}
	cd ${PORTSDIR}/audio/${i} && ${MAKE} package
.endfor

.include <bsd.port.mk>
