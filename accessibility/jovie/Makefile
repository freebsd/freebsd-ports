# New ports collection makefile for:	ktts
# Date created:		2010-03-27
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ktts
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	accessibility kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DISTNAME=	kdeaccessibility-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE text-to-speech subsystem

BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml
LIB_DEPENDS=	speechd.5:${PORTSDIR}/accessibility/speech-dispatcher

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdeprefix kdelibs automoc4
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build uic_build rcc_build
USE_LDCONFIG=	yes
DISTINFO_FILE=	${PORTSDIR}/accessibility/kdeaccessibility4/distinfo
MAKE_JOBS_SAFE=	yes

CMAKE_ARGS+=	-DKDE4_JOVIE_ALSA:BOOL=OFF

BUILD_WRKSRC=	${WRKSRC}/jovie
INSTALL_WRKSRC=	${BUILD_WRKSRC}

post-patch:
	${REINPLACE_CMD} -e 's|speechd|$$$\{SPEECHD_LIBRARY}|g' \
		${PATCH_WRKSRC}/jovie/kcmkttsmgr/CMakeLists.txt \
		${PATCH_WRKSRC}/jovie/jovie/CMakeLists.txt

post-install:
	cd ${WRKSRC}/doc/jovie && ${MAKE} install
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
