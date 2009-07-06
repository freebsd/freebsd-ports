# New ports collection makefile for:	xmms-kde
# Date created:			27 April 2001
# Whom:				Jan Jungnickel <jan@jungnickel.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-kde
PORTVERSION=	3.2
PORTREVISION=	5
CATEGORIES=	audio kde
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Integrates XMMS into the KDE3 Panel

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		tag.6:${PORTSDIR}/audio/taglib \
		smpeg.1:${PORTSDIR}/multimedia/smpeg \
		xmms.4:${PORTSDIR}/multimedia/xmms

USE_KDELIBS_VER=	3
USE_GNOME=	gtk12 gnometarget
USE_SDL=	sdl
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--with-xmms-prefix=${LOCALBASE} \
		--with-smpeg-prefix=${LOCALBASE} \
		--with-vorbis-prefix=${LOCALBASE} \
		--with-taglib-prefix=${LOCALBASE} \
		ac_cv_path_PATH_NOATUN=no \
		ac_cv_path_PATH_AMAROK=no \
		ac_cv_path_PATH_MPLAYER=no
USE_LDCONFIG=	yes

CFLAGS+=	-DHAVE_NOATUN -DHAVE_AMAROK -DHAVE_MPLAYER

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^INCLUDES/s| -g||g' ${WRKSRC}/xmms-kde/Makefile.in

.include <bsd.port.post.mk>
