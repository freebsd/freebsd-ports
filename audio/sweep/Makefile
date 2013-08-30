# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sweep
PORTVERSION=	0.9.3
PORTREVISION=	8
PORTEPOCH=	1
CATEGORIES=	audio gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sound editor for the GNOME/GTK+2 desktop

LIB_DEPENDS=	mad:${PORTSDIR}/audio/libmad \
		samplerate:${PORTSDIR}/audio/libsamplerate \
		sndfile:${PORTSDIR}/audio/libsndfile \
		vorbis:${PORTSDIR}/audio/libvorbis \
		speex:${PORTSDIR}/audio/speex

USE_BZIP2=	yes
USES=		pathfix gettext pkgconfig gmake
USE_GNOME=	gtk20
USE_AUTOTOOLS=	libtool

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-extralibdir=${LOCALBASE}/lib \
		--with-extraincdir=${LOCALBASE}/include \
		--with-vorbis-libraries=${LOCALBASE}/lib \
		--with-vorbis-includes=${LOCALBASE}/include/vorbis \
		--with-ogg-libraries=${LOCALBASE}/lib \
		--with-ogg-includes=${LOCALBASE}/include/ogg

MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's|^ac_enable_alsa=yes|ac_enable_alsa=no|g ; \
		s|$${datadir}|$${datarootdir}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
