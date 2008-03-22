# New ports collection makefile for:	audacity-devel
# Date created:				14 Sep 2006
# Whom:					Jackson Low <xxjack12xx@gmail.com>
#
# $FreeBSD$

PORTNAME=	audacity
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	xxjack12xx@gmail.com
COMMENT=	Audacity is a GUI editor for digital audio waveforms

BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip

CONFLICTS=	audacity-[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}-src-${PORTVERSION}-beta

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GCC=	4.2+

USE_WX=		2.6
WX_COMPS=	wx

MAN1=		audacity.1
MANCOMPRESSED=	yes

OPTIONS=	ID3TAG	"ID3 tag support"		off \
		MAD	"Mad MP3 audio decoder support"	on \
		VORBIS	"OGG/Vorbis audio support"	on

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && ${OSVERSION} >= 501103
SSE_CFLAGS=	-mno-sse -mno-sse2
.endif

CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${SSE_CFLAGS} ${PTHREAD_CFLAGS}" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include ${SSE_CFLAGS} ${PTHREAD_CFLAGS}" \
		WX_CONFIG=${WX_CONFIG}

.if !defined(NOPORTDOCS)
MAKE_ENV=	DOC=yes
.endif

CONFIGURE_ARGS+=	--with-portaudio=v18
.if !defined(WITHOUT_MAD)
CONFIGURE_ARGS+=	--with-libmad=system
LIB_DEPENDS+=		mad.2:${PORTSDIR}/audio/libmad
.else
CONFIGURE_ARGS+=	--without-libmad
.endif

.if !defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=	--with-vorbis=system
LIB_DEPENDS+=		vorbis.4:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--without-vorbis
.endif

.if defined(WITH_ID3TAG)
CONFIGURE_ARGS+=	--with-id3tag=system
LIB_DEPENDS+=		id3tag.0:${PORTSDIR}/audio/libid3tag
.else
CONFIGURE_ARGS+=	--without-id3tag
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,^sndfile.c : .*,,' \
		${WRKSRC}/lib-src/libsndfile/src/Makefile.in
.if ${ARCH} != "i386" && ${ARCH} != "amd64"
	@${REINPLACE_CMD} -E -e 's,-msse2?,,g' \
		${WRKSRC}/lib-src/soundtouch/source/SoundTouch/Makefile.in
.endif

.include <bsd.port.post.mk>
