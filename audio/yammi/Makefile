# New ports collection makefile for:	yammi
# Date created:				27 September 2003
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	yammi
PORTVERSION=	1.2.rc
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.2.r/.2-r/}

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	A QT-based music manager with fuzzy search

LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis \
		id3-3.8.3:${PORTSDIR}/audio/id3lib

OPTIONS=	ARTS "Arts backend support" on \
		XMMS "XMMS backend support" off \
		NOATUN "Noatun backend support" on

USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--program-prefix='' --enable-threading=yes --enable-mt=yes
USE_REINPLACE=	yes
USE_KDELIBS_VER=3

.include <bsd.port.pre.mk>

.if defined(WITHOUT_ARTS)
.if defined(WITHOUT_XMMS)
.if defined(WITHOUT_NOATUN)
IGNORE=	You must define at least one backend for yammi
.endif
.endif
.endif

.if !defined(WITHOUT_ARTS)
CONFIGURE_ARGS+=--with-arts
LIB_DEPENDS+=	artsgui:${PORTSDIR}/multimedia/kdemultimedia3
.else
CONFIGURE_ARGS+=--without-arts
.endif

.if !defined(WITHOUT_NOATUN)
RUN_DEPENDS+=	noatun:${PORTSDIR}/multimedia/kdemultimedia3
.endif

.if !defined(WITHOUT_XMMS)
CONFIGURE_ARGS+=--enable-xmms
BUILD_DEPENDS+= xmms-config:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS+=   xmms.4:${PORTSDIR}/multimedia/xmms
.else
CONFIGURE_ARGS+=--disable-xmms
.endif

.include <bsd.port.post.mk>
