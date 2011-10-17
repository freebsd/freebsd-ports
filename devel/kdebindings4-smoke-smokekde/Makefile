# New ports collection makefile for:	kdebindings4-smoke
# Date created:		2008-08-19
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	smokekde
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	kdebindings-smoke-
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	SMOKE bindings for KDE

LIB_DEPENDS=	okularcore.1:${PORTSDIR}/graphics/okular \
		kateinterfaces.5:${PORTSDIR}/editors/kate \
		smokeqtcore.3:${PORTSDIR}/devel/kdebindings4-smoke-smokeqt \
		soprano.4:${PORTSDIR}/textproc/soprano \
		smokebase.3:${PORTSDIR}/devel/kdebindings4-smoke-smokegen

CONFLICTS=	kdebindings-smoke-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix pimlibs akonadi automoc4
USE_QT_VER=	4
QT_COMPONENTS=	dbus designer gui network opengl qt3support sql svg xml \
		qmake_build moc_build uic_build rcc_build
USE_BZIP2=	yes
USE_CMAKE=	yes
# Attica bindings often cause the build to coredump.
CMAKE_ARGS+=	-DWITH_LibAttica:BOOL=FALSE
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

pre-configure:
	${REINPLACE_CMD} -e '/kde-config.xml/ s|$${SMOKE_GEN_BIN}|smokegen|' \
		${WRKSRC}/kdecore/CMakeLists.txt

.include <bsd.port.mk>
