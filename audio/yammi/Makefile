# New ports collection makefile for:	yammi
# Date created:				27 September 2003
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	yammi
PORTVERSION=	1.0.r1
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.0.r/.0-rc/}

MAINTAINER=	avleeuwen@piwebs.com
COMMENT=	A QT-based music manager with fuzzy search

LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis \
		id3-3.8.3:${PORTSDIR}/audio/id3lib \
		xmms.4:${PORTSDIR}/multimedia/xmms

USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--program-prefix='' --enable-threading=yes --enable-mt=yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/noatun)
WITH_NOATUN=yes
.endif # exists(${LOCALBASE}/bin/noatun)

.if defined(WITH_NOATUN)
BUILD_DEPENDS+=	noatun:${PORTSDIR}/multimedia/kdemultimedia3
WITH_KDE=yes
.else
CONFIGURE_ARGS+=	--disable-noatun
.endif # defined(WITH_NOATUN)

.if exists(${LOCALBASE}/lib/libkdecore.so)
WITH_KDE=yes
.endif # exists(${LOCALBASE}/lib/libkdecore.so)

.if defined(WITH_KDE)
USE_KDELIBS_VER=3
.else
CONFIGURE_ARGS+=	--disable-KDE
.endif # defined(WITH_KDE)

pre-configure:
	@${REINPLACE_CMD} -e 's@-lpthread@${PTHREAD_LIBS}@g' ${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e 's@$$(DESTDIR)$$(KDEDIR)@$$(prefix)@g' ${WRKSRC}/yammi/docs/en/Makefile

.include <bsd.port.post.mk>
