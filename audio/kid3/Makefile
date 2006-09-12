# New ports collection makefile for:   kid3
# Date created:                2006-08-02
# Whom:                        Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kid3
PORTVERSION=	0.7
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	makc@issp.ac.ru
COMMENT=	MP3/Ogg/FLAC tag editor for KDE

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		FLAC.7:${PORTSDIR}/audio/flac \
		ogg.5:${PORTSDIR}/audio/libogg \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		tunepimp-0.4.3:${PORTSDIR}/audio/libtunepimp-old

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS+=CFLAGS=-I${LOCALBASE}/include/tunepimp-0.4 \
		LDFLAGS=-L${LOCALBASE}/lib/tunepimp-0.4

post-patch:
	@${REINPLACE_CMD} -e 's|-ltunepimp|-ltunepimp-0.4|g' \
		-e 's|<tunepimp/tp_c.h>|<tunepimp-0.4/tunepimp/tp_c.h>|g' \
	${WRKSRC}/configure ${WRKSRC}/kid3/musicbrainzclient.h \
		${WRKSRC}/admin/Makefile

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	does not compile on FreeBSD 4.x
.endif

.include <bsd.port.post.mk>

