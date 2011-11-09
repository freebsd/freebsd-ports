# New ports collection makefile for:	portaudio
# Date created:		18 May 2003
# Whom:			michaelnottebrock@gmx.net and lioux@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	portaudio
DISTVERSION=	19_20071207
CATEGORIES=	audio
MASTER_SITES=	http://www.portaudio.com/archives/
DISTNAME=	pa_stable_v${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable cross-platform Audio API

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-alsa	\
		--libdir=${PREFIX}/lib/${PORTNAME}2 --includedir=${PREFIX}/include/${PORTNAME}2
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}2

LATEST_LINK=	${PORTNAME}2
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libjack.so)
WITH_JACK=	yes
.endif
.if !defined(WITH_JACK)
CONFIGURE_ARGS+=	--without-jack
.else
# Avoid a circular dependency
CONFIGURE_ARGS+=	--with-jack
#LIB_DEPENDS+=	jack.0:${PORTSDIR}/audio/jack
.endif

pre-configure:
# replace obsolete headers, and fix up thread library
	${FIND} ${WRKSRC} -type f \
		| ${XARGS} -x -n 10 \
			${REINPLACE_CMD} -E \
				-e 's|malloc.h|stdlib.h|' \
				-e 's|-lpthread|${PTHREAD_LIBS}|'
	${REINPLACE_CMD} -e '/pkgconfig/s|$$[(]libdir[)]|${PREFIX}/libdata|' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
