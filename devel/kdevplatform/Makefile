# New ports collection makefile for:	kdevplatform
# Date created:		Sun Aug 23 17:14:39 UTC 2009
# Whom:			Golyashov Sergei <svvord@mail.ru>
#
# $FreeBSD$

PORTNAME=	kdevplatform
PORTVERSION=	${KDEVELOP_VERSION:S/4./1./}
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDEVELOP_BRANCH}/kdevelop/${KDEVELOP_VERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE development platform

LIB_DEPENDS=	svn_client-1.0:${PORTSDIR}/devel/subversion \
		boost_thread.4:${PORTSDIR}/devel/boost-libs \
		qjson.0:${PORTSDIR}/devel/qjson

RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/katepart.so:${PORTSDIR}/editors/kate

USE_BZIP2=	yes
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus gui network qtestlib \
		qmake_build moc_build uic_build rcc_build
MAKE_JOBS_SAFE=	yes

post-patch:
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/kdevplatform|$${LIB_INSTALL_DIR}/kdevplatform/cmake|g' \
		${PATCH_WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
