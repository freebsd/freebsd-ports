# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	beast
PORTVERSION=	0.7.8
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://dist.testbit.eu/beast/%SUBDIR%/
MASTER_SITE_SUBDIR=	v${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful music composition and modular synthesis application

LICENSE=	LGPL21

LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib \
		libmad.so:${PORTSDIR}/audio/libmad \
		libvorbisfile.so:${PORTSDIR}/audio/libvorbis \
		libguile.so:${PORTSDIR}/lang/guile
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

OPTIONS_DEFINE=		DEBUG
OPTIONS_DEFINE_i386=	SSE

USE_BZIP2=	yes
USES=		desktop-file-utils gmake gettext pathfix pkgconfig shared-mime-info
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

DEBUG_CONFIGURE_ENABLE=	debug

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
	@${REINPLACE_CMD} -e \
		's|-DG_DISABLE_DEPRECATED||' ${WRKSRC}/bse/Makefile.am \
		${WRKSRC}/bse/Makefile.in

.include <bsd.port.post.mk>
