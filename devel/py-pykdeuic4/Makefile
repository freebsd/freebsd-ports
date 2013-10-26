# $FreeBSD$

PORTNAME=	pykdeuic4
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde python
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pykde4-${PORTVERSION}
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Enhanced version of pyuic4

USE_KDE4=	kdelibs automoc4 pykde4
USE_PYTHON=	2.5+
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_XZ=		yes
DISTINFO_FILE=	${PORTSDIR}/devel/py-pykde4/distinfo
USES=		cmake:outsource

WRKSRC=		${WRKDIR}/${DISTNAME}/tools/${PORTNAME}

PLIST_SUB+=	PYTHON_VER=${PYTHON_VER}

NO_STAGE=	yes
pre-configure:
	${REINPLACE_CMD} -e 's,$${PYTHON_SITE_PACKAGES_INSTALL_DIR},${PYTHONPREFIX_SITELIBDIR},g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
