# New ports collection makefile for:	kdevplatform
# Date created:		Sun Aug 23 17:14:39 UTC 2009
# Whom:			Golyashov Sergei <svvord@mail.ru>
#
# $FreeBSD$

PORTNAME=	kdevplatform
PORTVERSION=	${KDEVELOP_VERSION:S/4./1./}
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDEVELOP_BRANCH}/kdevelop/${KDEVELOP_VERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE development platform

LIB_DEPENDS=	svn_client-1.0:${PORTSDIR}/devel/subversion \
		boost_thread.4:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdelibs kdeprefix automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib assistant assistantclient clucene \
		dbus designer help gui multimedia network \
		opengl qt3support qtestlib script sql svg \
		scripttools webkit xml xmlpatterns phonon \
		qmake_build moc_build uic_build rcc_build

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/kdevplatform|$${LIB_INSTALL_DIR}/kdevplatform/cmake|g' \
		${PATCH_WRKSRC}/CMakeLists.txt

.include <bsd.port.post.mk>
