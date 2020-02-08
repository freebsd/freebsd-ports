# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	libsbml
PORTVERSION=	5.18.0
CATEGORIES=	biology devel
MASTER_SITES=	SF/sbml/libsbml/${PORTVERSION}/stable
DISTNAME=	libSBML-${PORTVERSION}-core-src

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	API Library for Working with SBML File

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		cmake gnome iconv:build pathfix
USE_GNOME=	libxml2

USE_CXXSTD=	c++98
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/libsbml-${PORTVERSION}

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	EXAMPLES PYTHON RUBY
OPTIONS_SUB=	yes

PYTHON_BUILD_DEPENDS=	swig3.0:devel/swig30
PYTHON_USES=		python:2.7
PYTHON_CMAKE_BOOL=	WITH_PYTHON
PYTHON_CMAKE_ON=	-DPYTHON_EXECUTABLE="${PYTHON_CMD}" \
			-DPYTHON_INCLUDE_DIR="${PYTHON_INCLUDEDIR}" \
			-DPYTHON_LIBRARY="${PYTHONBASE}/lib/lib${PYTHON_VERSION}.so"
PYTHON_BINARY_ALIAS=	swig=swig3.0
RUBY_BUILD_DEPENDS=	swig3.0:devel/swig30
RUBY_USE=		ruby=yes
RUBY_CMAKE_BOOL=	WITH_RUBY
RUBY_BINARY_ALIAS=	swig=swig3.0

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g; /$${DOCUMENTATION_FILES}/ s|^|#|' ${WRKSRC}/CMakeLists.txt

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} '! -name *Makefile*'

.include <bsd.port.mk>
