# New ports collection makefile for:	tunepimp
# Date Created:				11 Aug 2004
# Whom:					Lauri Watts <lauri@kde.org>
#
# $FreeBSD$
#

PORTNAME=	libtunepimp
PORTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/

MAINTAINER=	lauri@kde.org
COMMENT=	Client library for musicbrainz

LIB_DEPENDS=	vorbis:${PORTSDIR}/audio/libvorbis \
		FLAC:${PORTSDIR}/audio/flac \
		mad:${PORTSDIR}/audio/libmad \
		ogg:${PORTSDIR}/audio/libogg \
		expat:${PORTSDIR}/textproc/expat2 \
		musicbrainz:${PORTSDIR}/audio/libmusicbrainz

CONFLICTS=	trm-0*
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|#CFLAGS=|g ; \
		 s|^CXXFLAGS=|#CXXFLAGS=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lthr|${PTHREAD_LIBS}|g' \
		${WRKSRC}/lib/threads/posix/Makefile.in

.include <bsd.port.mk>
