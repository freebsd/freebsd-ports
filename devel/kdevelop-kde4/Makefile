# Created by: Golyashov Sergei <svvord@mail.ru>
# $FreeBSD$

PORTNAME=	kdevelop
DISTVERSION=	${KDEVELOP_VERSION}
PORTREVISION=	4
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDEVELOP_BRANCH}/kdevelop/${DISTVERSION}/src
DIST_SUBDIR=	KDE/kdevelop/${KDEVELOP_VERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plugin extensible IDE for KDE

LIB_DEPENDS=	libkdevplatforminterfaces.so:${PORTSDIR}/devel/kdevplatform
RUN_DEPENDS=	gmake:${PORTSDIR}/devel/gmake

USE_KDE4=	kdehier kdelibs kdeprefix workspace automoc4
USE_QT4=	qmake_build moc_build uic_build rcc_build \
		corelib declarative gui help script webkit xml
USES=		cmake gmake shared-mime-info tar:xz

OPTIONS_DEFINE=	OKTETA PHP NLS
OPTIONS_DEFAULT=	OKTETA PHP
OPTIONS_SUB=	yes

OKTETA_DESC=	Hex editing support via Okteta
OKTETA_LIB_DEPENDS=	libokteta1core.so:${PORTSDIR}/devel/okteta

PHP_DESC=	PHP support for KDevelop
PHP_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/kdevphplanguagesupport.so:${PORTSDIR}/devel/kdevelop-php

NLS_USES=	gettext
NLS_CMAKE_OFF=	-DBUILD_po:BOOL=FALSE

post-patch:
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d; /SharedMimeInfo/ d' \
		${PATCH_WRKSRC}/app/CMakeLists.txt

.include <bsd.port.mk>
