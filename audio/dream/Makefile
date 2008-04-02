# New ports collection makefile for:	Dream DRM Receiver
# Date created:				1st september 2006
# Whom:					Soeren Straaarup <xride@x12.dk>
#
# $FreeBSD$

PORTNAME=	dream
PORTVERSION=	1.6.25
PORTREVISION=	2
CATEGORIES=	audio hamradio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	drm
DISTNAME=	drm-${PORTVERSION}

MAINTAINER=	xride@FreeBSD.org
COMMENT=	Digital Radio Mondiale (DRM) software receiver

LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw \
		qwt4.4:${PORTSDIR}/x11-toolkits/qwt4 \
		faad.0:${PORTSDIR}/audio/faad

BROKEN=		Needs DRM enabled in FAAD

USE_X_PREFIX=	yes
USE_QT_VER=	3
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -I${LOCALBASE}/include \
		${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

PLIST_FILES=	bin/drm

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/include/qwt|${LOCALBASE}/include/qwt4|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lqwt|-lqwt4|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|neaacdec.h|faad.h|g' ${WRKSRC}/common/sourcedecoders/AudioSourceDecoder.cpp
	@${REINPLACE_CMD} -e 's|DRMCH_SBR_PS_STEREO|DRMCH_SBR_STEREO|g' ${WRKSRC}/common/sourcedecoders/AudioSourceDecoder.cpp

.include <bsd.port.mk>
