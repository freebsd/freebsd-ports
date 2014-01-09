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
QMAKE_SOURCE_PATH=	${WRKSRC}/src

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
IGNORE=		sources need more patching for debug build
.endif

.if ! ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET=	install_target
.endif

post-patch:
	@${RM} -f ${WRKSRC}/src/documentation/html/gettingstarted.html.orig

.include <bsd.port.mk>
