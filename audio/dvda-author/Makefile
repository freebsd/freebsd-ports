# Created by: dieringe@zedat.fu-berlin.de
# $FreeBSD$

PORTNAME=	dvda-author
PORTVERSION=	09.05
PORTREVISION=	9
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	SF/dvd-audio/${PORTNAME}-core/${PORTNAME}-${PORTVERSION}-core
DISTNAME=	${PORTNAME}-${PORTVERSION}-7

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Author and playback unencrypted and uncompressed Audio-DVDs

LIB_DEPENDS=	FLAC:${PORTSDIR}/audio/flac \
	ogg:${PORTSDIR}/audio/libogg \
	sox.1:${PORTSDIR}/audio/sox \
	samplerate.1:${PORTSDIR}/audio/libsamplerate \
	png15:${PORTSDIR}/graphics/png

MAN1=		dvda-author.1

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/FLAC

NO_STAGE=	yes
USE_AUTOTOOLS=	libltdl
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-flac=${LOCALBASE}/lib/libFLAC.so \
	--with-ogg=${LOCALBASE}/lib/libogg.so \
	--enable-glibc
USE_CSTD=	gnu89

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--docdir=${WRKDIR}/doc
.endif

post-patch:
	@${REINPLACE_CMD} 's|-std=c99||g' \
		${WRKSRC}/configure \
		${WRKSRC}/libats2wav/Makefile.in
	@${REINPLACE_CMD} 's|-std=c99 -O3||' \
		${WRKSRC}/fixwav/src/Makefile.in

.include <bsd.port.mk>
