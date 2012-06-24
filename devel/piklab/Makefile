# New ports collection makefile for:	piklab
# Date created:		2007-11-19
# Whom:			Michael Nottebrock <lofi@kiste>
#
# $FreeBSD$
#

PORTNAME=	piklab
PORTVERSION=	0.16.0
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE IDE for microcontroller development

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
USE_QT4=	corelib gui qt3support qtestlib xml \
		moc_build qmake_build rcc_build uic_build
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix sharedmime
USE_GETTEXT=	yes
USE_CMAKE=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		piklab-hex.1 piklab-prog.1 piklab.1x

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/install/s|^|#|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		'/CMAKE_BUILD_TYPE/s|^|#| ; \
		 /KDE4/s|INCLUDE_DIRS|INCLUDES|' ${WRKSRC}/cmake/Piklab.cmake
	@${REINPLACE_CMD} -e \
		'/install/s|share/man|man|' ${WRKSRC}/man/CMakeLists.txt

.include <bsd.port.post.mk>
