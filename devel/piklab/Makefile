# Created by: Michael Nottebrock <lofi@kiste>
# $FreeBSD$

PORTNAME=	piklab
PORTVERSION=	0.16.2
PORTREVISION=	3
CATEGORIES=	devel kde
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE/Qt IDE for microcontroller development

LICENSE=	GPLv2+

DOS2UNIX_FILES=	cmake/Piklab.cmake
USE_QT4=	corelib gui qt3support qtestlib xml \
		moc_build qmake_build rcc_build uic_build
USES=		cmake gettext readline dos2unix tar:bzip2

OPTIONS_DEFINE=	KDE4
OPTIONS_DEFAULT=	KDE4
OPTIONS_SUB=	yes

KDE4_USES=	shared-mime-info
KDE4_USE=	KDE4=automoc4,kdelibs,kdeprefix
KDE4_CMAKE_OFF=	-DQT_ONLY:BOOL=ON \
		-DLOCALE_INSTALL_DIR:STRING="${PREFIX}/share/locale"

BROKEN_sparc64=		does not compile on sparc64

post-patch:
	@${REINPLACE_CMD} -e \
		'/install/s|^|#|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's,share/man,man,' ${WRKSRC}/man/CMakeLists.txt

.include <bsd.port.mk>
