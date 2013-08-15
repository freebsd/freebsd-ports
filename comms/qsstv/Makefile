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

LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3 \
		hamlib:${PORTSDIR}/comms/hamlib \
		asound:${PORTSDIR}/audio/alsa-lib
BUILD_DEPENDS=	v4l_compat>=0:${PORTSDIR}/multimedia/v4l_compat

USE_QT4=	gui network moc_build qmake_build rcc_build uic_build

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

do-configure:
	@cd ${WRKSRC}; \
	    ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS} ${DISTNAME}.pro

.include <bsd.port.mk>
