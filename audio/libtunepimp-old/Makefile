# New ports collection makefile for:	tunepimp
# Date Created:				11 Aug 2004
# Whom:					Lauri Watts <lauri@kde.org>
#
# $FreeBSD$
#

PORTNAME=	libtunepimp-old
PORTVERSION=	0.4.4
PORTEPOCH=	2
CATEGORIES=	audio
MASTER_SITES=	http://ftp.musicbrainz.org/pub/musicbrainz/ \
		ftp://ftp.au.musicbrainz.org/pub/musicbrainz/
DISTNAME=	libtunepimp-${PORTVERSION}

MAINTAINER=	fluffy@Fluffy.Khv.RU
COMMENT=	Client library for musicbrainz

LIB_DEPENDS=	FLAC:${PORTSDIR}/audio/flac \
		expat:${PORTSDIR}/textproc/expat2 \
		mad:${PORTSDIR}/audio/libmad \
		mp4v2:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2 \
		musicbrainz:${PORTSDIR}/audio/libmusicbrainz \
		ogg:${PORTSDIR}/audio/libogg \
		tag:${PORTSDIR}/audio/taglib \
		vorbis:${PORTSDIR}/audio/libvorbis

CONFLICTS=	trm-0*
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--libdir=${PREFIX}/lib/tunepimp-0.4 --includedir=${PREFIX}/include/tunepimp-0.4
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -liconv"
USE_LDCONFIG=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/tunepimp-0.4
USE_LDCONFIG=	${PREFIX}/lib/tunepimp-0.4

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g ; \
		 s|^CPPFLAGS=|#CPPFLAGS=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lthr|${PTHREAD_LIBS}|g' \
		${WRKSRC}/lib/threads/posix/Makefile.in

post-configure:
	@${REINPLACE_CMD} -e 's|\(^LDFLAGS =.*\)|\1 ${PTHREAD_LIBS} -liconv|g' \
		${WRKSRC}/examples/Makefile
	@${REINPLACE_CMD} -e \
	's|PREFIX"/lib/tunepimp/plugins"|PREFIX"/lib/tunepimp-0.4/tunepimp/plugins"|g' \
		${WRKSRC}/lib/tunepimp.cpp

.include <bsd.port.mk>
