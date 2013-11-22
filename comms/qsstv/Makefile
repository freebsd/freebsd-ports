# $FreeBSD$

PORTNAME=	qsstv
PORTVERSION=	7.1.7
CATEGORIES=	comms hamradio
MASTER_SITES=	http://users.telenet.be/on4qz/qsstv/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	shurd@sasktel.net
COMMENT=	Amateur Radio SSTV/FAX reception program for unix

LIB_DEPENDS=	libfftw3.so:${PORTSDIR}/math/fftw3 \
		libhamlib.so:${PORTSDIR}/comms/hamlib \
		libasound.so:${PORTSDIR}/audio/alsa-lib
BUILD_DEPENDS=	v4l_compat>=0:${PORTSDIR}/multimedia/v4l_compat

USES=		qmake
USE_QT4=	gui network moc_build rcc_build uic_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
INSTALL_WRKSRC=	${WRKSRC}/src
INSTALL_TARGET=	install_target
.endif

post-patch:
	@${RM} -f ${WRKSRC}/src/documentation/html/gettingstarted.html.orig
	@${REINPLACE_CMD} -e 's|%%DOCSDIR%%|${DOCSDIR}|g' \
	    ${WRKSRC}/src/configdialog.cpp ${WRKSRC}/src/src.pro
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
	    ${WRKSRC}/src/src.pro

.include <bsd.port.mk>
