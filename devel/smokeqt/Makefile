# $FreeBSD$

PORTNAME=	smokeqt
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	SMOKE bindings for Qt

LIB_DEPENDS=	qscintilla2:${PORTSDIR}/devel/qscintilla2 \
		qwt.5:${PORTSDIR}/x11-toolkits/qwt5

CONFLICTS=	kdebindings-smoke-4.[0-6].*

USE_KDE4=	kdehier kdeprefix smokegen qimageblitz
USE_QT4=	corelib dbus declarative designer_build gui help \
		multimedia network opengl phonon qtestlib script \
		sql svg webkit xml xmlpatterns \
		qmake_build moc_build uic_build rcc_build
USE_XZ=		yes
USES=		cmake:outsource
USE_LDCONFIG=	yes

.include <bsd.port.mk>
