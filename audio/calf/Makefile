# Created by: <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	calf
PORTVERSION=	0.0.60
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio plug-in pack for LV2 and JACK environments

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	fftw3>0:${PORTSDIR}/math/fftw3
LIB_DEPENDS=	libfluidsynth.so:${PORTSDIR}/audio/fluidsynth \
		libjack.so:${PORTSDIR}/audio/jack \
		libfftw3f.so:${PORTSDIR}/math/fftw3-float \
		libexpat.so:${PORTSDIR}/textproc/expat2

USES=		compiler:c++11-lib gmake libtool pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		DOCS LASH LV2
OPTIONS_DEFAULT=	LASH LV2
OPTIONS_SUB=		yes

LASH_LIB_DEPENDS=	liblash.so:${PORTSDIR}/audio/lash
LASH_CONFIGURE_WITH=	lash
LV2_DESC=		LV2 audio plugin
LV2_BUILD_DEPENDS=	lv2core>0:${PORTSDIR}/audio/lv2core
LV2_RUN_DEPENDS=	lv2core>0:${PORTSDIR}/audio/lv2core
LV2_CONFIGURE_WITH=	lv2

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
CXXFLAGS+=	-fno-inline -finline-functions-called-once
.endif

post-patch:
	@${FIND} ${BUILD_WRKSRC} -name '*.cpp' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc.h>|<cstdlib>|'
	@${REINPLACE_CMD} -e \
		's|"GNU strip"|"strip"| ; \
		 /CXXFLAGS/s|-O3 .* -Wall|-Wall|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/AM_CXXFLAGS/s|-finline-limit=80|| ; \
		 /calf.so/s|$$(pkglibdir)|../../calf|' \
		${WRKSRC}/src/Makefile.in

pre-build:
.if ${PORT_OPTIONS:MLV2}
	@${MKDIR} ${WRKDIR}/calfmakerdf
	@(cd ${WRKSRC} && ${PAX} -rw . ${WRKDIR}/calfmakerdf)
	@${REINPLACE_CMD} -e 's|\(PKGLIBDIR\).*|\1 "${STAGEDIR}${DATADIR}"|' \
		${WRKDIR}/calfmakerdf/config.h
	@(cd ${WRKDIR}/calfmakerdf/src && ${DO_MAKE_BUILD} calfmakerdf)
.endif

post-install:
.if ${PORT_OPTIONS:MLV2}
	@(cd ${WRKDIR}/calfmakerdf/src && ./calfmakerdf -m ttl \
		-p ${STAGEDIR}${PREFIX}/lib/lv2/calf.lv2)
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/calf.lv2/calflv2gui.so
.endif

.include <bsd.port.post.mk>
