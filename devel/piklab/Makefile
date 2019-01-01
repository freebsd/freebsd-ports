# Created by: Michael Nottebrock <lofi@kiste>
# $FreeBSD$

PORTNAME=	piklab
PORTVERSION=	0.16.2
PORTREVISION=	8
CATEGORIES=	devel kde
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE/Qt IDE for microcontroller development

LICENSE=	GPLv2+

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

DOS2UNIX_FILES=	cmake/Piklab.cmake
USE_QT=		corelib gui qt3support qtestlib xml \
		moc_build qmake_build rcc_build uic_build network
USES=		cmake gettext qt:4 readline dos2unix tar:bzip2
USE_CXXSTD=	gnu++98

BROKEN=			does not link
BROKEN_sparc64=		does not compile on sparc64

post-patch:
	@${REINPLACE_CMD} -e \
		'/install/s|^|#|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's,share/man,man,' ${WRKSRC}/man/CMakeLists.txt

.include <bsd.port.mk>
