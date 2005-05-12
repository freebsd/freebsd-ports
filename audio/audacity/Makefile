# New ports collection makefile for:	audacity
# Date created:				21 Jul 2001
# Whom:					Marc van Woerkom <3d@freebsd.org>
#
# $FreeBSD$

PORTNAME=	audacity
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	craig@yekse.gank.org
COMMENT=	Audacity is a GUI editor for digital audio waveforms

BUILD_DEPENDS+=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24

WRKSRC=		${WRKDIR}/${PORTNAME}-src-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=	15

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && ${OSVERSION} >= 501103
SSE_CFLAGS=	-mno-sse -mno-sse2
.endif
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include ${SSE_CFLAGS} ${PTHREAD_CFLAGS}" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include ${SSE_CFLAGS} ${PTHREAD_CFLAGS}" \
		WX_CONFIG=${X11BASE}/bin/wxgtk2-2.4-config
CONFIGURE_ARGS+=	--with-id3=no

.if !defined(NOPORTDOCS)
MAKE_ENV=	DOC=yes
.endif

.if !defined(WITHOUT_MAD)
CONFIGURE_ARGS+=	--with-libmad=system
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad
.else
CONFIGURE_ARGS+=	--without-libmad
.endif

.if !defined(WITHOUT_VORBIS)
CONFIGURE_ARGS+=	--with-vorbis=system
LIB_DEPENDS+=	vorbis.3:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=	--without-vorbis
.endif

pre-everything::
.if !defined(WITHOUT_MAD)
	@${ECHO_MSG} "You can disable support for libmad (MP3) by defining WITHOUT_MAD."
.endif
.if !defined(WITHOUT_VORBIS)
	@${ECHO_MSG} "You can disable support for vorbis by defining WITHOUT_VORBIS."
.endif

MAN1=		audacity.1
MANCOMPRESSED=	yes

.include <bsd.port.post.mk>
