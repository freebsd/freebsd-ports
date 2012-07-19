# New ports collection makefile for:	libfishsound
# Date created:		2010-05-28
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
#
# $FreeBSD$
#

PORTNAME=	libfishsound
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/libfishsound/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A programing interface to decode/encode audio data

LIB_DEPENDS=	FLAC:${PORTSDIR}/audio/flac \
		speex:${PORTSDIR}/audio/speex \
		vorbis:${PORTSDIR}/audio/libvorbis

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

OPTIONS=	DOXYGEN	"Doxygen is required for generating documents" off

.include <bsd.port.options.mk>

.if !defined(NOPORTDOCS) && defined(WITH_DOXYGEN)
BUILD_DEPENDS+=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen
PORTDOCS=	*
.endif

post-patch:
.if defined(NOPORTDOCS) || !defined(WITH_DOXYGEN)
	@${REINPLACE_CMD} -e '/^SUBDIRS = / s| doc||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
