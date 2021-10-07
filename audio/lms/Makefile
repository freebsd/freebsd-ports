PORTNAME=	lms
DISTVERSIONPREFIX=	v
DISTVERSION=	3.27.0
CATEGORIES=	audio www

MAINTAINER=	bram@cbbg.nl
COMMENT=	Web based music streaming client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS+=	libavutil.so:multimedia/ffmpeg \
		libboost_system.so:devel/boost-libs \
		libconfig.so:devel/libconfig \
		libgtest.so:devel/googletest \
		libtag.so:audio/taglib \
		libwt.so:www/wt
RUN_DEPENDS+=	ffmpeg:multimedia/ffmpeg

USES=		cmake compiler:c++17-lang pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	epoupon
USE_RC_SUBR=	lms

OPTIONS_DEFINE=		PAM
OPTIONS_SINGLE=		IMGLIB
OPTIONS_SINGLE_IMGLIB=	GM STB
OPTIONS_DEFAULT=	GM PAM

PAM_DESC=	Use the PAM authentication backend
IMGLIB_DESC=	Image library backend
GM_DESC=	GraphicsMagick++
STB_DESC=	STB single-header file libraries

PAM_CMAKE_OFF=	-DUSE_PAM=OFF
GM_CMAKE_ON=	-DIMAGE_LIBRARY=GraphicsMagick++
STB_CMAKE_ON=	-DIMAGE_LIBRARY=STB

GM_LIB_DEPENDS+=	libGraphicsMagick++.so:graphics/GraphicsMagick \
			libGraphicsMagick.so:graphics/GraphicsMagick
STB_BUILD_DEPENDS+=	${LOCALBASE}/include/stb/stb_image.h:devel/stb

USERS=		_lms
GROUPS=		_lms

post-install:
	@${MV} ${STAGEDIR}${DATADIR}/lms.conf ${STAGEDIR}${LOCALBASE}/etc/lms.conf.sample
	@${MKDIR} ${STAGEDIR}/var/run/${PORTNAME}
	@${RM} ${STAGEDIR}${DATADIR}/default.service

.include <bsd.port.mk>
