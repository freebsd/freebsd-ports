# New ports collection makefile for:	kdebindings4-python-pykdeuic4
# Date created:		2010-05-30
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pykdeuic4
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde python
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}kdebindings-
DISTNAME=	pykde4-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	An enhanced version of pyuic4

USE_KDE4=	kdehier kdelibs kdeprefix automoc4 pykde4
USE_PYTHON=	2.5+
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build uic_build rcc_build
USE_BZIP2=	yes
DISTINFO_FILE=	${PORTSDIR}/devel/kdebindings4-python-pykde4/distinfo
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/tools/${PORTNAME}

pre-configure:
	${REINPLACE_CMD} -e 's,$${PYTHON_SITE_PACKAGES_INSTALL_DIR},${PYTHONPREFIX_SITELIBDIR},g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
