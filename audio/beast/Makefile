# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	beast
PORTVERSION=	0.7.8
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://testbit.eu/pub/dists/beast/v${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful music composition and modular synthesis application

LICENSE=	LGPL21

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libmad.so:audio/libmad \
		libvorbisfile.so:audio/libvorbis \
		libguile.so:lang/guile
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		desktop-file-utils gettext gmake libtool pathfix pkgconfig \
		shared-mime-info shebangfix tar:bzip2
SHEBANG_FILES=	autotools/intltool-merge
# Fails to build with GCC 4.9, cf. PR 196849.
USE_GCC=	4.8
USE_GNOME=	intltool libgnomecanvas
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules \
		--enable-osspcm=/dev/dsp \
		--enable-ossmidi=/dev/midi
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CXXFLAGS+=	-fpermissive
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION="${PORTVERSION}"
OPTIONS_SUB=	yes

OPTIONS_DEFINE=		DEBUG
OPTIONS_DEFINE_i386=	SSE
OPTIONS_DEFINE_amd64=	SSE
OPTIONS_DEFAULT_i386=	${MACHINE_CPU:Msse:tu}
OPTIONS_DEFAULT_amd64=	SSE

DEBUG_CONFIGURE_ENABLE=	debug
SSE_VARS=	SSE_FLAGS="-mmmx -msse"

BROKEN_powerpc64=	Does not build

MAKE_JOBS_UNSAFE=	yes

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

.include <bsd.port.mk>
