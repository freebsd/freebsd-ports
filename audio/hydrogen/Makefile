# New ports collection makefile for:	Hydrogen
# Date created:			23 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		hydrogen
PORTVERSION=		0.9.0.b1
PORTREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}-0.9.0beta1

MAINTAINER=		jylefort@brutele.be
COMMENT=		An advanced drum machine

LIB_DEPENDS=		sndfile:${PORTSDIR}/audio/libsndfile \
			FLAC:${PORTSDIR}/audio/flac

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_REINPLACE=		yes
USE_GETOPT_LONG=	yes
USE_QT_VER=		3
CPPFLAGS=		-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS=		-L${LOCALBASE}/lib -L${X11BASE}/lib
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=		--program-prefix="" --disable-alsa-seq

MAN1=			hydrogen.1

OPTIONS=		JACK "JACK support" off \
			OSS "OSS support" on \
			LRDF "LRDF support" off

.include <bsd.port.pre.mk>

.if defined(WITH_JACK)
LIB_DEPENDS+=		jack:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=	--disable-jack-support
.endif

.if defined(WITHOUT_OSS)
CONFIGURE_ARGS+=	--disable-oss-support
.endif

.if defined(WITH_LRDF)
LIB_DEPENDS+=		lrdf:${PORTSDIR}/textproc/liblrdf
.else
CONFIGURE_ARGS+=	--disable-lrdf-support
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|-O2||g' \
		-e 's|CXXFLAGS="-O3"||' \
		-e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|/usr|${LOCALBASE}|' \
		${WRKSRC}/lib/fx/LadspaFX.cpp \
		${WRKSRC}/lib/PreferencesMng.cpp

.include <bsd.port.post.mk>
