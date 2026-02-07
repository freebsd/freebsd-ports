PORTNAME=	qsstv
PORTVERSION=	9.5.8
PORTREVISION=	4
CATEGORIES=	comms hamradio
MASTER_SITES=	${WWW}/${PORTNAME}/downloads/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio SSTV/FAX reception program for unix
WWW=		https://www.qsl.net/on4qz/

LICENSE=	GPLv3

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libhamlib.so:comms/hamlib \
		libopenjp2.so:graphics/openjpeg \
		libpulse.so:audio/pulseaudio \
		libv4l2.so:multimedia/libv4l
BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat

USES=		compiler:c++11-lang gl pkgconfig qmake:outsource qt:5
USE_QT=		buildtools core gui network widgets xml
USE_GL=		gl

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/qsstv \
		share/applications/qsstv.desktop \
		share/pixmaps/qsstv.png

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
BUILD_DEPENDS+=	doxygen:devel/doxygen
LIB_DEPENDS+=	libqwt6.so:x11-toolkits/qwt6
PLIST_FILES+=	bin/qsstv.debug
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
			-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
			-e 's|%%DOCSDIR%%|${DOCSDIR}|g' \
			-e 's|%%PERL%%|${PERL}|g' \
		${WRKSRC}/qsstv.pro \
		${WRKSRC}/config/directoriesconfig.cpp \
		${WRKSRC}/documentation/manual/manual.doxy \
		${WRKSRC}/documentation/manual/manual.txt \
		${WRKSRC}/documentation/api/api.doxy
	${RM} ${WRKSRC}/documentation/manual/manual.txt.*
	${RM} ${WRKSRC}/documentation/manual/manual.*.orig

post-install:
	${INSTALL_DATA} ${WRKSRC}/qsstv.desktop ${STAGEDIR}/${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/icons/qsstv.png ${STAGEDIR}${PREFIX}/share/pixmaps
	-${RM} ${STAGEDIR}/${DOCSDIR}/manual.doxy
	-${RM} ${STAGEDIR}/${DOCSDIR}/doxygen_sqlite3.db
	-${RM} ${STAGEDIR}/${DOCSDIR}/*.bak
	-${RM} ${STAGEDIR}/${DOCSDIR}/*.orig

.include <bsd.port.mk>
