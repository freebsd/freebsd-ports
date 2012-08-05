# New ports collection makefile for: ices
# Date created:         11 Nov 2002
# Whom:                 Michael Nottebrock <michaelnottebrock@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	ices
PORTVERSION=	0.4
PORTREVISION=	10
CATEGORIES=	audio net
MASTER_SITES=	http://svn.xiph.org/releases/ices/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An mp3 streaming source client for icecast 2

LIB_DEPENDS=	shout.5:${PORTSDIR}/audio/libshout2 \
		xml2.5:${PORTSDIR}/textproc/libxml2

OPTIONS_DEFINE=	FLAC FAAD VORBIS PYTHON
OPTIONS_DEFAULT=	PYTHON

CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib
USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=  yes
LATEST_LINK=	ices0
USE_RC_SUBR=	ices0
SUB_FILES+=	message message-bin
CONFIGURE_ARGS+=--program-suffix=0

.if !defined(PACKAGE_BUILDING)
PKGMESSAGE=	${WRKDIR}/message
.else
PKGMESSAGE=	${WRKDIR}/message-bin
.endif

MAN1=		ices0.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac \
		mp3lame:${PORTSDIR}/audio/lame
.else
CONFIGURE_ARGS+=--without-flac
.endif

.if ${PORT_OPTIONS:MFAAD}
LIB_DEPENDS+=	faad:${PORTSDIR}/audio/faad \
		mp3lame:${PORTSDIR}/audio/lame
.else
CONFIGURE_ARGS+=--without-faad
.endif

.if ${PORT_OPTIONS:MPYTHON}
BUILD_DEPENDS+=	python:${PORTSDIR}/lang/python
RUN_DEPENDS+=	python:${PORTSDIR}/lang/python
.else
CONFIGURE_ARGS+=--without-python
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	vorbis:${PORTSDIR}/audio/libvorbis \
		mp3lame:${PORTSDIR}/audio/lame
.else
CONFIGURE_ARGS+=--without-vorbis
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
