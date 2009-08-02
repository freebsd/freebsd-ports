# New ports collection makefile for:   dvda-author
# Date created:        9 October 2007
# Whom:                dieringe@zedat.fu-berlin.de
#
# $FreeBSD$
#

PORTNAME=	dvda-author
PORTVERSION=	09.05
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	dvd-audio
DISTNAME=	${PORTNAME}-${PORTVERSION}-7

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Author and playback unencrypted and uncompressed Audio-DVDs

LIB_DEPENDS=	FLAC.10:${PORTSDIR}/audio/flac \
	ogg.6:${PORTSDIR}/audio/libogg \
	sox.1:${PORTSDIR}/audio/sox \
	samplerate.1:${PORTSDIR}/audio/libsamplerate \
	png.5:${PORTSDIR}/graphics/png

BUILD_DEPENDS=	${LOCALBASE}/lib/libiberty.a:${PORTSDIR}/devel/gnulibiberty

MAN1=		dvda-author.1

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/FLAC

USE_AUTOTOOLS=  libltdl
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-flac=${LOCALBASE}/lib/libFLAC.so \
	--with-ogg=${LOCALBASE}/lib/libogg.so \
	--enable-glibc
.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=        --docdir=${WRKDIR}/doc
.endif
CONFIGURE_ENV=  CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
 
.include <bsd.port.mk>
