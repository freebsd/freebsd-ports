# Created by: <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	calf
PORTVERSION=	0.0.19
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

OPTIONS_DEFINE=	LASH LV2
OPTIONS_DEFAULT=LASH LV2
OPTIONS_SUB=	yes
LV2_DESC=	LV2 audio plugin

USES=		gmake pkgconfig compiler:env
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

LASH_LIB_DEPENDS=	liblash.so:${PORTSDIR}/audio/lash
LASH_CONFIGURE_WITH=	lash
LV2_BUILD_DEPENDS=	lv2core>0:${PORTSDIR}/audio/lv2core
LV2_RUN_DEPENDS=	lv2core>0:${PORTSDIR}/audio/lv2core
LV2_CONFIGURE_WITH=	lv2

.include <bsd.port.pre.mk>

post-patch:
	@${FIND} ${BUILD_WRKSRC} -name '*.cpp' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>|'
	@${REINPLACE_CMD} -e '/CXXFLAGS/s|-O3||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/calf.so/s|$$(pkglibdir)|../../calf|' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|src\.size();|src->size();|' \
		${WRKSRC}/src/calf/buffer.h
	@${REINPLACE_CMD} -e 's|data\[(1<<IntBits)+1\]|data[]|' \
		${WRKSRC}/src/calf/fixed_point.h
.if ${COMPILER_TYPE} == "clang"
	@${REINPLACE_CMD} -e 's|-finline-functions -finline-functions-called-once||' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-finline-limit=80||' ${WRKSRC}/src/Makefile.in
.endif

pre-build:
.if ${PORT_OPTIONS:MLV2}
	@${MKDIR} ${WRKDIR}/calfmakerdf
	@(cd ${WRKSRC} && ${PAX} -rw . ${WRKDIR}/calfmakerdf)
	@${REINPLACE_CMD} -e 's|\(PKGLIBDIR\).*|\1 "${STAGEDIR}${DATADIR}"|' \
		${WRKDIR}/calfmakerdf/config.h
	@(cd ${WRKDIR}/calfmakerdf/src && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} -j${MAKE_JOBS_NUMBER} ${MAKE_ARGS} \
		calfmakerdf)
.endif

post-install:
.if ${PORT_OPTIONS:MLV2}
	@(cd ${WRKDIR}/calfmakerdf/src && ./calfmakerdf -m ttl \
		-p ${STAGEDIR}${PREFIX}/lib/lv2/calf.lv2)
.endif

.include <bsd.port.post.mk>
