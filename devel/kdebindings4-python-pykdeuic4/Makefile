# New ports collection makefile for:	kdebindings4-python-pykdeuic4
# Date created:		2010-05-30
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdebindings
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde python
PKGNAMESUFFIX=	-pykdeuic4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	An enhanced version of pyuic4

BINDLANG=	python
BINDMODULE=	pykde4

USE_PYTHON=	2.5+
.include "${.CURDIR}/../../devel/kdebindings4/files/Makefile.kdebindings"
#override USE_KDE4 from Makefile.kdebindings:
USE_KDE4=	kdelibs automoc4 pykde4

CMAKE_SOURCE_PATH=	${BUILD_WRKSRC}
CONFIGURE_WRKSRC=	${BUILD_WRKSRC}
BUILD_WRKSRC=	${WRKSRC}/python/pykde4/tools
INSTALL_WRKSRC=	${BUILD_WRKSRC}

pre-configure:
	${REINPLACE_CMD} -e 's,$${SIP_DEFAULT_SIP_DIR},${PREFIX}/${SIPDIR_REL},g' \
		-e 's,$${PYTHON_SITE_PACKAGES_DIR},${PYTHONPREFIX_SITELIBDIR},g' \
		${BUILD_WRKSRC}/pykdeuic4/CMakeLists.txt

.include <bsd.port.mk>
