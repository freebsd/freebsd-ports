# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sweep
PORTVERSION=	0.9.3
PORTREVISION=	11
PORTEPOCH=	1
CATEGORIES=	audio gnome
MASTER_SITES=	SF

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Sound editor for the GNOME/GTK+2 desktop

LICENSE=	GPLv2

LIB_DEPENDS=	libmad.so:audio/libmad \
		libsamplerate.so:audio/libsamplerate \
		libsndfile.so:audio/libsndfile \
		libvorbis.so:audio/libvorbis \
		libspeex.so:audio/speex

USES=		pathfix gettext pkgconfig gmake tar:bzip2 libtool \
		desktop-file-utils
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-extralibdir=${LOCALBASE}/lib \
		--with-extraincdir=${LOCALBASE}/include \
		--with-vorbis-libraries=${LOCALBASE}/lib \
		--with-vorbis-includes=${LOCALBASE}/include/vorbis \
		--with-ogg-libraries=${LOCALBASE}/lib \
		--with-ogg-includes=${LOCALBASE}/include/ogg
CONFIGURE_ENV=	LIBS="`pkg-config --libs gmodule-2.0`"

post-patch:
	@${REINPLACE_CMD} -e 's|^ac_enable_alsa=yes|ac_enable_alsa=no|g ; \
		s|$${datadir}|$${datarootdir}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
