# New ports collection Makefile for: 	terminatorx
# Date created:			13 May 2002
# Whom:				Tilman Linneweh <freebsdports@arved.de
#
# $FreeBSD$

PORTNAME=	terminatorx
PORTVERSION=	3.72
CATEGORIES=	audio
MASTER_SITES=	http://www.terminatorx.cx/
DISTNAME=	terminatorX-${PORTVERSION}

MAINTAINER=	freebsdports@arved.de

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
.if !defined(WITHOUT_SOX)
BUILD_DEPENDS+=	sox:${PORTSDIR}/audio/sox
.endif
.if !defined(WITHOUT_VORBIS)
BUILD_DEPENDS+=	oggenc:${PORTSDIR}/audio/vorbis-tools
.endif

USE_GNOMENG=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

pre-everything:
.if !defined(WITHOUT_SOX)
	@${ECHO_MSG} "You can disable support for sox by defining WITHOUT_SOX."
.endif
.if !defined(WITHOUT_VORBIS)
	@${ECHO_MSG} "You can disable support for vorbis by defining WITHOUT_VORBIS."
.endif

post-patch:

.for i in main.cc \
	tX_audiofile.cc \
	tX_flash.c \
	tX_seqpar.cc \
	tX_vtt.cc \
	tX_widget.c
	${MV} ${WRKSRC}/src/$i ${WRKSRC}/src/$i.sed
	${SED} -e "s:malloc.h:stdlib.h:g" \
		${WRKSRC}/src/$i.sed >${WRKSRC}/src/$i
	${RM} ${WRKSRC}/src/$i.sed
.endfor

.include <bsd.port.mk>
