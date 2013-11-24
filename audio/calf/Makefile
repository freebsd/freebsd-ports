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
LV2_DESC=	LV2 audio plugin

USES=		gmake pkgconfig
USE_GNOME=	gtk20
USE_CSTD=	gnu89
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_SUB=	yes
LASH_LIB_DEPENDS=	liblash.so:${PORTSDIR}/audio/lash
LASH_CONFIGURE_WITH=	lash
LV2_BUILD_DEPENDS+=	lv2core>0:${PORTSDIR}/audio/lv2core
LV2_RUN_DEPENDS+=	lv2core>0:${PORTSDIR}/audio/lv2core
LV2_CONFIGURE_WITH=	lv2

post-patch:
	@${FIND} ${BUILD_WRKSRC} -name '*.cpp' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>|'
	@${REINPLACE_CMD} -e '/CXXFLAGS/s|-O3||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^install-data-am:/s|install-data-local||' \
		${WRKSRC}/Makefile.in

post-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install-data-local)

.include <bsd.port.mk>
