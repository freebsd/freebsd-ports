PORTNAME=	entropypianotuner
DISTVERSION=	1.3.0
CATEGORIES=	audio

MAINTAINER=	raggen@raggens.net
COMMENT=	Experimental software for tuning a piano
WWW=		https://gitlab.com/tp3/Entropy-Piano-Tuner

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/gpl_v3.md

LIB_DEPENDS+=	libfftw3.so:math/fftw3 \
		libuv.so:devel/libuv

USES=		compiler:c++14-lang desktop-file-utils gl qmake qt:6 tar:bzip2
USE_GITLAB=	yes
GL_ACCOUNT=	tp3
GL_PROJECT=	Entropy-Piano-Tuner
GL_TAGNAME=	f9181865345be460ab5a08a009b49caae1f0d37c
GL_TUPLE=	tp3:qtmidi:1c3bf17:qtmidi/thirdparty/qtmidi \
		chwick:qwt-lib:c778d34:qwt_lib/thirdparty/qwt-lib \
		tp3:tp3log:3861a44:tp3log/thirdparty/tp3log
USE_GL+=	gl opengl
USE_LDCONFIG=	${PREFIX}/lib/entropypianotuner \
		${PREFIX}/lib/entropypianotuner/algorithms
USE_QT+=	base multimedia svg

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/modules/core/calculation/calculationmanager.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/entropypianotuner ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/entropypianotuner
	${INSTALL_LIB} ${WRKSRC}/bin/libcore.so.1.0.0 ${STAGEDIR}${PREFIX}/lib/entropypianotuner/

	${RLN} ${STAGEDIR}${PREFIX}/lib/entropypianotuner/libcore.so.1.0.0  ${STAGEDIR}${PREFIX}/lib/entropypianotuner/libcore.so
	${RLN} ${STAGEDIR}${PREFIX}/lib/entropypianotuner/libcore.so.1.0.0  ${STAGEDIR}${PREFIX}/lib/entropypianotuner/libcore.so.1
	${RLN} ${STAGEDIR}${PREFIX}/lib/entropypianotuner/libcore.so.1.0.0  ${STAGEDIR}${PREFIX}/lib/entropypianotuner/libcore.so.1.0

	${MKDIR} ${STAGEDIR}${PREFIX}/lib/entropypianotuner/algorithms
	${INSTALL_LIB} ${WRKSRC}/bin/algorithms/libentropyminimizer.so ${STAGEDIR}${PREFIX}/lib/entropypianotuner/algorithms/
	${INSTALL_LIB} ${WRKSRC}/bin/algorithms/libpitchraise.so ${STAGEDIR}${PREFIX}/lib/entropypianotuner/algorithms/
	${INSTALL_LIB} ${WRKSRC}/bin/algorithms/libresettorecording.so ${STAGEDIR}${PREFIX}/lib/entropypianotuner/algorithms/

	${INSTALL_DATA} ${WRKSRC}/app/shared/applications/entropypianotuner.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${REINPLACE_CMD} -e 's|Categories=Application;|Categories=AudioVideo;Audio;|g' ${STAGEDIR}${PREFIX}/share/applications/entropypianotuner.desktop
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps
	${INSTALL_DATA} ${WRKSRC}/app/shared/icons/hicolor/128x128/mimetypes/application-ept.png \
	    ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/entropypianotuner.png

.include <bsd.port.mk>
