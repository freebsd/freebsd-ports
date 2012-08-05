# New ports collection makefile for:	piklab
# Date created:		2007-11-19
# Whom:			Michael Nottebrock <lofi@kiste>
#
# $FreeBSD$
#

PORTNAME=	piklab
PORTVERSION=	0.16.1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE IDE for microcontroller development

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	KDE4
OPTIONS_DEFAULT=KDE4

USE_BZIP2=	yes
USE_QT4=	corelib gui qt3support qtestlib xml \
		moc_build qmake_build rcc_build uic_build
USE_GETTEXT=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		piklab-hex.1 piklab-prog.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKDE4}
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix sharedmime
INSTALLS_ICONS=	yes
MAN1+=		piklab.1x
PLIST_SUB+=	KDE4=""
.else
CMAKE_ARGS+=	-DQT_ONLY:BOOL=ON \
		-DLOCALE_INSTALL_DIR:STRING="${PREFIX}/share/locale"
PLIST_SUB+=	KDE4="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb:${PORTSDIR}/devel/libusb
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/man/s|^|#| ; \
		 /install/s|^|#|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		'/CMAKE_BUILD_TYPE/s|^|#| ; \
		 /KDE4/s|INCLUDE_DIRS|INCLUDES|' ${WRKSRC}/cmake/Piklab.cmake

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/piklab-*.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MKDE4}
	${INSTALL_MAN} ${WRKSRC}/man/piklab.1x ${MANPREFIX}/man/man1
.endif

.include <bsd.port.post.mk>
