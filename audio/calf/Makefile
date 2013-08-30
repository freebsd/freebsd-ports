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
LIB_DEPENDS=	fluidsynth:${PORTSDIR}/audio/fluidsynth \
		jack:${PORTSDIR}/audio/jack \
		fftw3f:${PORTSDIR}/math/fftw3-float \
		expat:${PORTSDIR}/textproc/expat2

OPTIONS_DEFINE=	LASH LV2
OPTIONS_DEFAULT=LASH LV2
LV2_DESC=	LV2 audio plugin

USES=		gmake
USE_GCC=	any
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		calfjackhost.1
MAN7=		calf.7

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLASH}
LIB_DEPENDS+=	lash:${PORTSDIR}/audio/lash
.else
CONFIGURE_ARGS+=--without-lash
.endif

.if ${PORT_OPTIONS:MLV2}
BUILD_DEPENDS+=	lv2core>0:${PORTSDIR}/audio/lv2core
RUN_DEPENDS+=	lv2core>0:${PORTSDIR}/audio/lv2core
PLIST_SUB+=	LV2=""
.else
CONFIGURE_ARGS+=--without-lv2
PLIST_SUB+=	LV2="@comment "
.endif

post-patch:
	@${FIND} ${BUILD_WRKSRC} -name '*.cpp' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>|'
	@${REINPLACE_CMD} -e '/CXXFLAGS/s|-O3||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^install-data-am:/s|install-data-local||' \
		${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install-data-local)
.endif

.include <bsd.port.mk>
