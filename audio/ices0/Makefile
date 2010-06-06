# New ports collection makefile for: ices
# Date created:         11 Nov 2002
# Whom:                 Michael Nottebrock <michaelnottebrock@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	ices
PORTVERSION=	0.4
PORTREVISION=	9
CATEGORIES=	audio net
MASTER_SITES=	http://svn.xiph.org/releases/ices/

MAINTAINER=	steinex@nognu.de
COMMENT=	An mp3 streaming source client for icecast 2

LIB_DEPENDS=	shout.5:${PORTSDIR}/audio/libshout2 \
		xml2.5:${PORTSDIR}/textproc/libxml2

OPTIONS=	FLAC "Enable flac transcoding support" Off \
		FAAD "Enable mpep4 transcoding support" Off \
		VORBIS "Enable ogg/vorbis transcoding support" Off \
		PYTHON "Enable Python scripting" On

CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=  yes
LATEST_LINK=	ices0
USE_RC_SUBR=	ices0.sh
SUB_FILES+=	message message-bin
CONFIGURE_ARGS+=--program-suffix=0

.if !defined(PACKAGE_BUILDING)
PKGMESSAGE=	${WRKDIR}/message
.else
PKGMESSAGE=	${WRKDIR}/message-bin
.endif

MAN1=		ices0.1

.include <bsd.port.pre.mk>

.if !defined(WITH_FLAC)
CONFIGURE_ARGS+=--without-flac
.else
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac \
		mp3lame:${PORTSDIR}/audio/lame
.endif

.if !defined(WITH_FAAD)
CONFIGURE_ARGS+=--without-faad
.else
LIB_DEPENDS+=	faad:${PORTSDIR}/audio/faad \
		mp3lame:${PORTSDIR}/audio/lame
.endif

.if defined(WITH_PYTHON)
BUILD_DEPENDS+=	python:${PORTSDIR}/lang/python
RUN_DEPENDS+=	python:${PORTSDIR}/lang/python
.else
CONFIGURE_ARGS+=--without-python
.endif

.if !defined(WITH_VORBIS)
CONFIGURE_ARGS+=--without-vorbis
.else
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis \
		mp3lame:${PORTSDIR}/audio/lame
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
