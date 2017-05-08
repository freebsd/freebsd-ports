# $FreeBSD$

PORTNAME=	pykdeuic4
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	devel kde kde-kde4 python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pykde4-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Enhanced version of pyuic4

USES=		cmake:outsource python:2 kde:4 shebangfix tar:xz
USE_KDE=	kdelibs automoc4 pykde4
USE_QT4=	moc_build qmake_build rcc_build uic_build
DISTINFO_FILE=	${.CURDIR:H:H}/devel/py-pykde4/distinfo

SHEBANG_FILES=	pykdeuic4.py

WRKSRC=		${WRKDIR}/${DISTNAME}/tools/${PORTNAME}

PLIST_SUB+=	PYTHON_VER=${PYTHON_VER}

pre-configure:
	${REINPLACE_CMD} -e 's,$${PYTHON_SITE_PACKAGES_INSTALL_DIR},${PYTHONPREFIX_SITELIBDIR},g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
