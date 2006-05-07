# New ports collection makefile for: icecast
# Date created:         28 Jan 1999
# Whom:                 Chip Marshall <chip@eboai.org>
#
# $FreeBSD$
#

PORTNAME=	icecast2
PORTVERSION=	2.3.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	audio net ipv6
MASTER_SITES=	http://svn.xiph.org/releases/icecast/
DISTNAME=	icecast-${PORTVERSION}

MAINTAINER=	lofi@freebsd.org
COMMENT=	A streaming mp3/ogg-vorbis audio server

LIB_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		shout.5:${PORTSDIR}/audio/libshout2 \
		speex.3:${PORTSDIR}/audio/speex \
		theora.2:${PORTSDIR}/multimedia/libtheora \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		xslt.2:${PORTSDIR}/textproc/libxslt

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	icecast2.sh
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
CONFIGURE_ENV=	OGG_PREFIX=${LOCALBASE} CFLAGS=-I${LOCALBASE}/include

WRKSRC=		${WRKDIR}/icecast-${PORTVERSION}

.include <bsd.port.pre.mk>

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
