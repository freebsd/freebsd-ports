# $FreeBSD$

PORTNAME=	smokeqt
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	SMOKE bindings for Qt

LIB_DEPENDS=	qscintilla2:${PORTSDIR}/devel/qscintilla2 \
		qwt.5:${PORTSDIR}/x11-toolkits/qwt5

CONFLICTS=	kdebindings-smoke-4.[0-6].*

USE_KDE4=	kdehier kdeprefix smokegen qimageblitz
USE_QT4=	dbus declarative designer gui help multimedia \
		network opengl phonon qt3support qtestlib \
		script sql svg xml xmlpatterns webkit \
		qmake_build moc_build uic_build rcc_build
USE_XZ=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
