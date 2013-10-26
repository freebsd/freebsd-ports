# $FreeBSD$

PORTNAME=	gwenview
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Image viewer and browser for KDE 4

LATEST_LINK=	${PORTNAME}-kde4

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		exiv2.12:${PORTSDIR}/graphics/exiv2

CONFLICTS=	kdegraphics-4.[0-6].*

USE_KDE4=	kactivities kdehier kdelibs kdeprefix libkipi libkonq \
		automoc4 soprano
USES=		cmake:outsource
USE_QT4=	corelib gui opengl qmake_build moc_build uic_build rcc_build
USE_XZ=		yes
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

# mkdtemp() is not defined in stdlib.h in FreeBSD 7.
.if ${OSVERSION} < 800000
EXTRA_PATCHES=	${FILESDIR}/extra-patch-importer__fileutils.cpp
.endif

.include <bsd.port.post.mk>
