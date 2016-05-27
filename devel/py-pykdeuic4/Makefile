# $FreeBSD$

PORTNAME=	pykdeuic4
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde python
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pykde4-${PORTVERSION}
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Enhanced version of pyuic4

USE_KDE4=	kdelibs automoc4 pykde4
USE_QT4=	moc_build qmake_build rcc_build uic_build
DISTINFO_FILE=	${.CURDIR:H:H}/devel/py-pykde4/distinfo
USES=		cmake:outsource python:2 tar:xz

WRKSRC=		${WRKDIR}/${DISTNAME}/tools/${PORTNAME}

PLIST_SUB+=	PYTHON_VER=${PYTHON_VER}

pre-configure:
	${REINPLACE_CMD} -e 's,$${PYTHON_SITE_PACKAGES_INSTALL_DIR},${PYTHONPREFIX_SITELIBDIR},g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
