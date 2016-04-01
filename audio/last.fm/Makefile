# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	last.fm
PORTVERSION=	1.5.4.26862
DISTVERSIONSUFFIX=	.src
PORTREVISION=	5
CATEGORIES=	audio net
MASTER_SITES=	http://cdn.last.fm/client/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Official last.fm radio player

LICENSE=	GPLv2

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libgpod.so:audio/libgpod \
		libmad.so:audio/libmad \
		libsamplerate.so:audio/libsamplerate \
		libfftw3f.so:math/fftw3-float

WRKSRC=		${WRKDIR}/last.fm-${PORTVERSION}

USES=		cpe dos2unix qmake:norecursive tar:bzip2
CPE_VENDOR=	last
DOS2UNIX_GLOB=	*.h *.cpp
USE_QT4=	moc_build rcc_build uic_build \
		gui network sql xml imageformats_run
LDFLAGS+=	-lz -L${LOCALBASE}/lib -lX11
QMAKE_SOURCE_PATH=	${WRKSRC}/LastFM.pro
USE_LDCONFIG=	yes

SUB_FILES=	pkg-install pkg-deinstall

post-patch:
	@${REINPLACE_CMD} -e \
		's|linux\*|unix|g' ${WRKSRC}/src/src.pro
	@${REINPLACE_CMD} -e \
		's|/usr/include/gpod|${LOCALBASE}/include/gpod| ; \
		 s|/usr/include/glib|${LOCALBASE}/include/glib| ; \
		 s|/usr/lib/glib|${LOCALBASE}/lib/glib| ; \
		 s|linux|freebsd|' ${WRKSRC}/src/mediadevices/ipod/ipod.pro
	@${REINPLACE_CMD} -e \
		's|^RUNDIR.*|RUNDIR=${PREFIX}/lib/last.fm|' \
		${WRKSRC}/bin/last.fm.sh
	@${REINPLACE_CMD} -e \
		's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/src/mediadevices/ipod/IpodDevice.cpp

pre-build:
	@${MKDIR} ${WRKSRC}/build/fplib/release

post-build:
	@(cd ${WRKSRC}/src/output/RtAudio \
		&& ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKE_ARGS} \
		&& ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS})
	@${SED} -e 's|/usr/local/share/|${PREFIX}/lib/|' \
		${FILESDIR}/last.fm.desktop > ${WRKDIR}/last.fm.desktop

do-install:
	(cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} last.fm.sh \
		${STAGEDIR}${PREFIX}/bin/last.fm)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/last.fm
	(cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} last.fm \
		${STAGEDIR}${PREFIX}/lib/last.fm)
.for i in libLastFmFingerprint libLastFmTools libMoose
	(cd ${WRKSRC}/bin && ${INSTALL_LIB} ${i}.so.1.0.0 \
		${STAGEDIR}${PREFIX}/lib/last.fm)
	${LN} -sf ${i}.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/last.fm/${i}.so.1.0
	${LN} -sf ${i}.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/last.fm/${i}.so.1
	${LN} -sf ${i}.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/last.fm/${i}.so
.endfor
	@(cd ${WRKSRC}/bin && ${COPYTREE_SHARE} data \
		${STAGEDIR}${PREFIX}/lib/last.fm)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/last.fm/services
	(cd ${WRKSRC}/bin/services && ${INSTALL_LIB} *.so \
		${STAGEDIR}${PREFIX}/lib/last.fm/services)
	(cd ${WRKDIR} && ${INSTALL_DATA} last.fm.desktop \
		${STAGEDIR}${DESKTOPDIR})
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/services
	(cd ${FILESDIR} && ${INSTALL_DATA} lastfm.protocol \
		${STAGEDIR}${PREFIX}/share/services)

.include <bsd.port.mk>
