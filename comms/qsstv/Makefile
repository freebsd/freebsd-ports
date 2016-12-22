# $FreeBSD$

PORTNAME=	qsstv
PORTVERSION=	9.2.4
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://users.telenet.be/on4qz/qsstv/downloads/ \
		LOCAL/db
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio SSTV/FAX reception program for unix

LICENSE=	GPLv3

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libhamlib.so:comms/hamlib \
		libopenjp2.so:graphics/openjpeg \
		libpulse.so:audio/pulseaudio \
		libv4l2.so:multimedia/libv4l
BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat

USES=		qmake
USE_QT5=	buildtools core gui network widgets xml
USE_GL+=	gl

OPTIONS_DEFINE=	DOCS
DOCS_CXXFLAGS=	-DWITH_DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
			-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
			-e 's|%%DOCSDIR%%|${DOCSDIR}|g' \
			-e 's|%%PERL%%|${PERL}|g' \
		${WRKSRC}/qsstv/qsstv.pro ${WRKSRC}/qwt/qwt.pro \
		${WRKSRC}/qsstv/config/directoriesconfig.cpp \
		${WRKSRC}/qsstv/documentation/manual/manual.doxy \
		${WRKSRC}/qsstv/documentation/manual/manual/gettingstarted.html \
		${WRKSRC}/qsstv/documentation/manual/manual.txt
	${RM} ${WRKSRC}/qsstv/documentation/manual/manual.txt.*
	${RM} ${WRKSRC}/qsstv/documentation/manual/manual.*.orig

post-install:
	-${RM} ${STAGEDIR}/${DOCSDIR}/manual.doxy
	-${RM} ${STAGEDIR}/${DOCSDIR}/doxygen_sqlite3.db
	-${RM} ${STAGEDIR}/${DOCSDIR}/*.bak
	-${RM} ${STAGEDIR}/${DOCSDIR}/*.orig

.include <bsd.port.mk>
