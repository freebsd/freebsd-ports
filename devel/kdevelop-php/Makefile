# $FreeBSD$

PORTNAME=	kdevelop-php
PORTVERSION=	${KDEVELOP_VERSION:S/4./1./}
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDEVELOP_BRANCH}/kdevelop/${KDEVELOP_VERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PHP support for KDevelop

LIB_DEPENDS=	kdevplatforminterfaces:${PORTSDIR}/devel/kdevplatform
BUILD_DEPENDS=	${KDE4_PREFIX}/bin/kdev-pg-qt:${PORTSDIR}/devel/kdevelop-pg-qt

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_XZ=		yes
USES=		cmake gmake
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	PHPDOCS NLS
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

PHPDOCS_DESC=	Integrate with PHP.net documentation

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPHPDOCS}
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/kdevphpdocs.so:${PORTSDIR}/devel/kdevelop-php-docs
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DBUILD_po:BOOL=Off
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
