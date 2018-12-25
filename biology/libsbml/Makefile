# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	libsbml
PORTVERSION=	5.17.0
CATEGORIES=	biology devel
MASTER_SITES=	SF/sbml/${PORTNAME}/${PORTVERSION}/stable
DISTNAME=	libSBML-${PORTVERSION}-core-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API Library for Working with SBML File

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.txt

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		cmake iconv:build
USE_CXXSTD=	c++98
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CFLAGS+=	-I${ICONV_PREFIX}/include
LDFLAGS+=	-L${ICONV_PREFIX}/lib

OPTIONS_DEFINE=	EXAMPLES PYTHON RUBY
OPTIONS_SUB=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

PYTHON_BUILD_DEPENDS=	swig3.0:devel/swig30
PYTHON_USES=		python:2.7
PYTHON_CMAKE_ON=	-DWITH_PYTHON:BOOL=ON \
			-DPYTHON_INCLUDE_DIR:STRING="${PYTHON_INCLUDEDIR}" \
			-DPYTHON_LIBRARY:STRING="${PYTHONBASE}/lib/lib${PYTHON_VERSION}.so" \
			-DPYTHON_EXECUTABLE:STRING="${PYTHON_CMD}"
PYTHON_BINARY_ALIAS=	swig=swig3.0

RUBY_BUILD_DEPENDS=	swig3.0:devel/swig30
RUBY_USE=		ruby=yes
RUBY_CMAKE_ON=		-DWITH_RUBY:BOOL=ON
RUBY_BINARY_ALIAS=	swig=swig3.0

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local/include|${LOCALBASE}/include| ; \
		s|/usr/local/lib|${LOCALBASE}/lib| ; \
		s|$${CMAKE_INSTALL_LIBDIR}/pkgconfig|libdata/pkgconfig| ; \
		/$${DOCUMENTATION_FILES}/s|^|#|' ${WRKSRC}/CMakeLists.txt

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR} '! -name *Makefile*'

.include <bsd.port.mk>
