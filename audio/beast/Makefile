# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	beast
PORTVERSION=	0.7.8
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://dist.testbit.eu/beast/%SUBDIR%/
MASTER_SITE_SUBDIR=	v${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful music composition and modular synthesis application

LICENSE=	LGPL21

LIB_DEPENDS=	asound:${PORTSDIR}/audio/alsa-lib \
		mad:${PORTSDIR}/audio/libmad \
		vorbisfile:${PORTSDIR}/audio/libvorbis \
		guile:${PORTSDIR}/lang/guile
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

OPTIONS_DEFINE_i386=	SSE

USE_BZIP2=	yes
NO_STAGE=	yes
USES=		gmake pathfix gettext pkgconfig
USE_GCC=	yes
USE_GNOME=	gnomehier libgnomecanvas
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules \
		--enable-osspcm=/dev/dsp \
		--enable-ossmidi=/dev/midi
USE_LDCONFIG=	yes

CXXFLAGS+=	-fpermissive
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="${PORTVERSION}"

MAN1=		beast.1 bsescm.1 bsewavetool.1 sfidl.1
MAN5=		bse.5

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc: array bound is not an integer constant
.endif

.if ${PORT_OPTIONS:MSSE} || ${ARCH} == "amd64"
PLIST_SUB+=	SSE=""
SSE_FLAGS=	-mmmx -msse
.else
PLIST_SUB+=	SSE="@comment "
SSE_FLAGS=	# none
.endif

.if empty(PORT_OPTIONS:MDEBUG)
CONFIGURE_ARGS+=--disable-debug
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^[[:space:]].*FLAGS -[Ofgp].*"/s|^|#| ; \
		 s|-mmmx -msse \(-ftree-vectorize\)|${SSE_FLAGS} \1| ; \
		 s|\(if test 0\) ==|\1 -eq| ; \
		 s|\(bseladspapath=\)$${|\1\\\$${| ; \
		 s|\(LDFLAGS=\)""|\1"$$LDFLAGS"|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|/bin/bash|${SH}|' ${WRKSRC}/mkrelease.sh
	@${REINPLACE_CMD} -e \
		's|BIRNET_.*_UINT == 0|1|' ${WRKSRC}/birnet/birnetcdefs.h
	@${REINPLACE_CMD} -e \
		's|; q|;| ; \
		 s|-o \(pipefail\)|\1|' ${WRKSRC}/docs/Makefile.in

.include <bsd.port.post.mk>
