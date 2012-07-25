# New ports collection makefile for:	kdevelop
# Date created:		Sun Aug 23 17:14:39 UTC 2009
# Whom:			Golyashov Sergei <svvord@mail.ru>
#
# $FreeBSD$

PORTNAME=	kdevelop
DISTVERSION=	${KDEVELOP_VERSION}
PORTREVISION=	2
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDEVELOP_BRANCH}/kdevelop/${DISTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Opensource IDE based on KDevPlatform, KDE, and Qt libraries

LIB_DEPENDS+=	kdevplatforminterfaces.5:${PORTSDIR}/devel/kdevplatform

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GMAKE=	yes
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix workspace
USE_QT4=	qmake_build moc_build uic_build rcc_build
MAKE_JOBS_SAFE=	yes

OPTIONS=	OKTETA	"Install Okteta plugin" on \
		PHP	"Install PHP support" on

LATEST_LINK=	${PORTNAME}-kde4

.include <bsd.port.options.mk>

.ifndef(WITHOUT_OKTETA)
LIB_DEPENDS+=	okteta1core:${PORTSDIR}/devel/kdesdk4
PLIST_SUB+=	OKTETA=""
.else
CMAKE_ARGS+=	WITH_LibOkteta:BOOL=FALSE
PLIST_SUB+=	OKTETA="@comment "
.endif

.ifndef(WITHOUT_PHP)
RUN_DEPENDS+=	${PREFIX}/lib/kde4/kdevphplanguagesupport.so:${PORTSDIR}/devel/kdevelop-php
.endif

.include <bsd.port.mk>
