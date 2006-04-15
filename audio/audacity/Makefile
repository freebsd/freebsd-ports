# New ports collection makefile for:	audacity
# Date created:				21 Jul 2001
# Whom:					Marc van Woerkom <3d@freebsd.org>
#
# $FreeBSD$

PORTNAME=	audacity
PORTVERSION=	1.2.4b
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	craig@yekse.gank.org
COMMENT=	Audacity is a GUI editor for digital audio waveforms

BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	wx_gtk2_core-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26

WRKSRC=		${WRKDIR}/${PORTNAME}-src-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GETTEXT=	yes

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
		WX_CONFIG=${X11BASE}/bin/wxgtk2-2.6-config

.if !defined(NOPORTDOCS)
MAKE_ENV=	DOC=yes
.endif

.if !defined(WITHOUT_MAD)
CONFIGURE_ARGS+=	--with-libmad=system
LIB_DEPENDS+=		mad.2:${PORTSDIR}/audio/libmad
.else
CONFIGURE_ARGS+=	--without-libmad
.endif

.if !defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=	--with-vorbis=system
LIB_DEPENDS+=		vorbis.3:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--without-vorbis
.endif

.if defined(WITH_ID3TAG)
CONFIGURE_ARGS+=	--with-id3tag=system
LIB_DEPENDS+=		id3tag.0:${PORTSDIR}/audio/libid3tag
.else
CONFIGURE_ARGS+=	--without-id3tag
.endif

.include <bsd.port.post.mk>
