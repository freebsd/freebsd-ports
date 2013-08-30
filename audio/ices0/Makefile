# Created by: Michael Nottebrock <michaelnottebrock@gmx.net>
# $FreeBSD$

PORTNAME=	ices
PORTVERSION=	0.4
PORTREVISION=	10
CATEGORIES=	audio net
MASTER_SITES=	http://svn.xiph.org/releases/ices/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MP3 streaming source client for Icecast 2

LIB_DEPENDS=	shout:${PORTSDIR}/audio/libshout2 \
		xml2:${PORTSDIR}/textproc/libxml2

OPTIONS_DEFINE=	FLAC FAAD VORBIS PYTHON
OPTIONS_DEFAULT=	PYTHON

USES=		gmake perl5
GNU_CONFIGURE=	yes
USE_RC_SUBR=	ices0

LATEST_LINK=	ices0
SUB_FILES=	message message-bin
CONFIGURE_ARGS=	--program-suffix=0

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if !defined(PACKAGE_BUILDING)
PKGMESSAGE=	${WRKDIR}/message
.else
PKGMESSAGE=	${WRKDIR}/message-bin
.endif

MAN1=		ices0.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac \
		mp3lame:${PORTSDIR}/audio/lame
.else
CONFIGURE_ARGS+=	--without-flac
.endif

.if ${PORT_OPTIONS:MFAAD}
LIB_DEPENDS+=	faad:${PORTSDIR}/audio/faad \
		mp3lame:${PORTSDIR}/audio/lame
.else
CONFIGURE_ARGS+=	--without-faad
.endif

.if ${PORT_OPTIONS:MPYTHON}
BUILD_DEPENDS+=	python:${PORTSDIR}/lang/python
RUN_DEPENDS+=	python:${PORTSDIR}/lang/python
.else
CONFIGURE_ARGS+=	--without-python
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis \
		mp3lame:${PORTSDIR}/audio/lame
.else
CONFIGURE_ARGS+=	--without-vorbis
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
