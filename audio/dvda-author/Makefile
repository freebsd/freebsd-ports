# New ports collection makefile for:   dvda-author
# Date created:        9 October 2007
# Whom:                dieringe@zedat.fu-berlin.de
#
# $FreeBSD$
#

PORTNAME=	dvda-author
PORTVERSION=	09.05
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	SF/dvd-audio/${PORTNAME}-core/${PORTNAME}-${PORTVERSION}-core
DISTNAME=	${PORTNAME}-${PORTVERSION}-7

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Author and playback unencrypted and uncompressed Audio-DVDs

LIB_DEPENDS=	FLAC.10:${PORTSDIR}/audio/flac \
	ogg.6:${PORTSDIR}/audio/libogg \
	sox.1:${PORTSDIR}/audio/sox \
	samplerate.1:${PORTSDIR}/audio/libsamplerate \
	png.5:${PORTSDIR}/graphics/png

MAN1=		dvda-author.1

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/FLAC

USE_AUTOTOOLS=	libltdl
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-flac=${LOCALBASE}/lib/libFLAC.so \
	--with-ogg=${LOCALBASE}/lib/libogg.so \
	--enable-glibc
.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--docdir=${WRKDIR}/doc
.endif
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.mk>
