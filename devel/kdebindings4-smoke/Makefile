# New ports collection makefile for:	kdebindings4-smoke
# Date created:		2008-08-19
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kdebindings
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	SMOKE bindings for Qt/KDE

LIB_DEPENDS=	qscintilla2.5:${PORTSDIR}/devel/qscintilla2 \
		qimageblitz.4:${PORTSDIR}/x11/qimageblitz \
		okularcore.1:${PORTSDIR}/graphics/kdegraphics4 \
		kateinterfaces.5:${PORTSDIR}/devel/kdesdk4 \
		qwt.5:${PORTSDIR}/x11-toolkits/qwt5

BINDLANG=	smoke

QT_COMPONENTS=	declarative help multimedia qt3support
USE_KDE4=	pimlibs
CMAKE_ARGS=	-DDISABLE_Attica:BOOL=TRUE
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

BUILD_WRKSRC=	${WRKSRC}/${BINDLANG}

.include "${.CURDIR}/../../devel/kdebindings4/files/Makefile.kdebindings"

pre-configure:
	@cd ${WRKSRC}/generator && ${SETENV} ${CMAKE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS}

pre-build:
	@cd ${WRKSRC}/generator && ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS}

pre-install:
	@cd ${WRKSRC}/generator && ${SETENV} ${MAKE_ENV} ${MAKE} ${INSTALL_TARGET}

.include <bsd.port.mk>
