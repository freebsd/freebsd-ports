# New ports collection makefile for:	sweep
# Date created:				25 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sweep
PORTVERSION=	0.9.1
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	freebsd@unixfreunde.de
COMMENT=	A sound editor for the GNOME/GTK 2.0 desktop

LIB_DEPENDS=	sndfile.1:${PORTSDIR}/audio/libsndfile \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		speex.3:${PORTSDIR}/audio/speex \
		mad.2:${PORTSDIR}/audio/mad

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-extralibdir=${LOCALBASE}/lib \
		--with-extraincdir=${LOCALBASE}/include \
		--with-vorbis=${LOCALBASE}/lib \
		--with-vorbis=${LOCALBASE}/include/vorbis \
		--with-ogg=${LOCALBASE}/lib \
		--with-ogg=${LOCALBASE}/include/ogg

MAN1=		sweep.1

.include <bsd.port.mk>
