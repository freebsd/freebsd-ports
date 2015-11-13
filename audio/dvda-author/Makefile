# Created by: dieringe@zedat.fu-berlin.de
# $FreeBSD$

PORTNAME=	dvda-author
PORTVERSION=	09.05
PORTREVISION=	13
PORTEPOCH=	1
CATEGORIES=	audio
MASTER_SITES=	SF/dvd-audio/${PORTNAME}-core/${PORTNAME}-${PORTVERSION}-core
DISTNAME=	${PORTNAME}-${PORTVERSION}-7

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	Author and playback unencrypted and uncompressed Audio-DVDs

BROKEN=		Fails to fetch
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac \
		libogg.so:${PORTSDIR}/audio/libogg \
		libsox.so:${PORTSDIR}/audio/sox \
		libsamplerate.so:${PORTSDIR}/audio/libsamplerate \
		libltdl.so:${PORTSDIR}/devel/libltdl \
		libpng.so:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/FLAC

USES=		tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-flac=${LOCALBASE}/lib/libFLAC.so \
	--with-ogg=${LOCALBASE}/lib/libogg.so \
	--enable-glibc
USE_CSTD=	gnu89

OPTIONS_DEFINE=	DOCS

DOCS_CONFIGURE_OFF=	--docdir=${WRKDIR}/doc

post-patch:
	@${REINPLACE_CMD} 's|-std=c99||g' \
		${WRKSRC}/configure \
		${WRKSRC}/libats2wav/Makefile.in
	@${REINPLACE_CMD} 's|-std=c99 -O3||' \
		${WRKSRC}/fixwav/src/Makefile.in

.include <bsd.port.mk>
