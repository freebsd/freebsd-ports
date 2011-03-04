# New ports collection makefile for:    audio/mp3splt-gtk
# Date created:                         05.09.2009
# Whom:                                 Timothy Beyer <beyert@cs.ucr.edu>
#
# $FreeBSD$

PORTNAME=	mp3splt-gtk
PORTVERSION=	0.5.7a
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF/mp3splt/${PORTNAME}/${PORTVERSION}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Utility to split mp3 and ogg files (via GTK Interface)

BUILD_DEPENDS=	audacious2:${PORTSDIR}/multimedia/audacious
LIB_DEPENDS=	mp3splt:${PORTSDIR}/audio/libmp3splt \
		mad.2:${PORTSDIR}/audio/libmad \
		ogg.7:${PORTSDIR}/audio/libogg \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		id3tag.0:${PORTSDIR}/audio/libid3tag

USE_AUTOTOOLS=	libltdl
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"
CONFIGURE_ARGS+=	--enable-audacious --with-mp3splt=${LOCALBASE} --with-mp3splt-includes=${LOCALBASE}/include --with-mp3splt-libraries=${LOCALBASE}/lib --disable-mp3splttest

MAN1=	mp3splt-gtk.1

post-patch:
	@${REINPLACE_CMD} -e 's|"audacious |& audclient |g' \
		${WRKSRC}/configure


.include <bsd.port.mk>
