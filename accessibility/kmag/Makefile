# New ports collection Makefile for:	kdeaccessibility
# Date created:				2008-01-31
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdeaccessibility
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	accessibility kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Accessibility applications for KDE4

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	opengl gui qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

MAN1=	kmag.1 \
	kmousetool.1 \
	kmouth.1

OPTIONS=	KTTS "Enable KTTS speech service" off

.include <bsd.port.options.mk>

.if defined(WITH_KTTS)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kttsd:${PORTSDIR}/accessibility/ktts
.endif

post-patch:
	${REINPLACE_CMD} -e '/macro_optional_add_subdirectory.*kttsd/d' \
		${PATCH_WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e '/add_subdirectory.*kttsd/d' \
		${PATCH_WRKSRC}/doc/CMakeLists.txt

.include <bsd.port.mk>
