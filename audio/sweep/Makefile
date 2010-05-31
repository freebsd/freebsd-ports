# New ports collection makefile for:	sweep
# Date created:				25 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sweep
PORTVERSION=	0.9.3
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	audio gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A sound editor for the GNOME/GTK 2.0 desktop

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad \
		samplerate.1:${PORTSDIR}/audio/libsamplerate \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		speex.1:${PORTSDIR}/audio/speex

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget gtk20
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-extralibdir=${LOCALBASE}/lib \
		--with-extraincdir=${LOCALBASE}/include \
		--with-vorbis-libraries=${LOCALBASE}/lib \
		--with-vorbis-includes=${LOCALBASE}/include/vorbis \
		--with-ogg-libraries=${LOCALBASE}/lib \
		--with-ogg-includes=${LOCALBASE}/include/ogg

MAN1=		sweep.1

post-patch:
	@${REINPLACE_CMD} -e 's|^ac_enable_alsa=yes|ac_enable_alsa=no|g ; \
	    	s|$${datadir}|$${datarootdir}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
