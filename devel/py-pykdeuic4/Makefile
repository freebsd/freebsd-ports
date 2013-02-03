# $FreeBSD$

PORTNAME=	pykdeuic4
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde python
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pykde4-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	An enhanced version of pyuic4

USE_KDE4=	kdelibs automoc4 pykde4
USE_PYTHON=	2.5+
USE_QT4=	corelib qmake_build moc_build uic_build rcc_build
USE_XZ=	yes
DISTINFO_FILE=	${PORTSDIR}/devel/py-pykde4/distinfo
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/tools/${PORTNAME}

pre-configure:
	${REINPLACE_CMD} -e 's,$${PYTHON_SITE_PACKAGES_INSTALL_DIR},${PYTHONPREFIX_SITELIBDIR},g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
