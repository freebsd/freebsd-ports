# New ports collection makefile for:    JuK
# Date created:                         Saturday 7 December 2002
# Whom:                                 Lauri Watts <lauri@kde.org>
#
# $FreeBSD$
#

PORTNAME=	juk
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	audio kde
MASTER_SITES=	http://developer.kde.org/~wheeler/files/src/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	JuK, a music manager and jukebox for KDE

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib
RUN_DEPENDS=	${LOCALBASE}/lib/kde3/kfile_mp3.so:${PORTSDIR}/multimedia/kdemultimedia3 \
		${LOCALBASE}/lib/kde3/kfile_ogg.so:${PORTSDIR}/multimedia/kdemultimedia3

USE_KDELIBS_VER=3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

CONFIGURE_TARGET=	--build=${ARCH}-portsbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g; s|-pedantic ||g; \
		s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
