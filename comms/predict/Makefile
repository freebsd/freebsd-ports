PORTNAME=	predict
PORTVERSION=	2.3.1
CATEGORIES=	comms astro hamradio
MASTER_SITES=	https://www.qsl.net/kd2bd/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Satellite tracking program for amateur radio satellites
WWW=		https://www.qsl.net/kd2bd/predict.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		ncurses

CONFLICTS_INSTALL=	liblinear # bin/predict

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/src/predict-2.3.1/|${PREFIX}/share/predict|g' ${WRKSRC}/predict.h

# I'm not building & installing clients/gsat-1 map kep_reload etc. only earthtrack
do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -I ${LOCALBASE}/include -o predict predict.c -L ${LOCALBASE}/lib -pthread -lm -lncursesw -lasound
	cd ${WRKSRC}/clients/earthtrack && ${CC} ${CFLAGS} -o earthtrack earthtrack.c -lm
	cd ${WRKSRC}/utils/moontracker && ${CC} ${CFLAGS} -o moontracker moontracker.c -lm

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/default
.for f in predict.db predict.qth predict.tle
	${INSTALL_DATA} ${WRKSRC}/default/$f ${STAGEDIR}${DATADIR}/default
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}/vocalizer
	cd ${WRKSRC}/vocalizer && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/vocalizer
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/pdf/predict.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/html/predict.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/text/predict.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/man/predict.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/predict ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/clients/earthtrack/earthtrack ${STAGEDIR}${PREFIX}/bin/
	${RLN} ${STAGEDIR}${PREFIX}/bin/earthtrack ${STAGEDIR}${PREFIX}/bin/earthtrack2
	${INSTALL_PROGRAM} ${WRKSRC}/utils/moontracker/moontracker ${STAGEDIR}${PREFIX}/bin/moontracker
	${INSTALL_SCRIPT} ${WRKSRC}/kepupdate ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/clients/&& ${COPYTREE_SHARE} samples ${STAGEDIR}${EXAMPLESDIR}
.include <bsd.port.mk>
