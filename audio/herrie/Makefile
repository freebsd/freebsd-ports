# New ports collection makefile for:	herrie
# Date created:				01 August 2006
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=	herrie
PORTVERSION=	0.1
CATEGORIES=	audio
MASTER_SITES=	http://www.il.fontys.nl/~ed/projects/herrie/distfiles/ \
		http://www.stack.nl/~ed/projects/herrie/distfiles/

MAINTAINER=	ed@fxq.nl
COMMENT=	A small command line interface music player

LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis \
		mad.2:${PORTSDIR}/audio/mad \
		sndfile.1:${PORTSDIR}/audio/libsndfile

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

PLIST_FILES=	bin/herrie

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		doesn't like 4.x thread libs
.endif

.include <bsd.port.post.mk>
