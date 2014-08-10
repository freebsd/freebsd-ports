# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	libsbml
PORTVERSION=	5.10.2
CATEGORIES=	biology devel
MASTER_SITES=	SF/sbml/${PORTNAME}/${PORTVERSION}/stable
DISTNAME=	libSBML-${PORTVERSION}-core-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API Library for Working with SBML File

LICENSE=	LGPL21

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		cmake:outsource iconv	
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CFLAGS+=	-I${ICONV_PREFIX}/include
LDFLAGS+=	-L${ICONV_PREFIX}/lib

OPTIONS_DEFINE=	EXAMPLES PYTHON RUBY
OPTIONS_SUB=	yes

PYTHON_BUILD_DEPENDS=	swig2.0:${PORTSDIR}/devel/swig20
PYTHON_USE=		python=yes
PYTHON_CMAKE_ON=	-DWITH_PYTHON:BOOL=ON \
			-DPYTHON_INCLUDE_DIR:STRING="${PYTHON_INCLUDEDIR}" \
			-DPYTHON_LIBRARY:STRING="${PYTHONBASE}/lib/lib${PYTHON_VERSION}.so" \
			-DPYTHON_EXECUTABLE:STRING="${PYTHON_CMD}"

RUBY_BUILD_DEPENDS=	swig2.0:${PORTSDIR}/devel/swig20
RUBY_USE=		ruby=yes
RUBY_CMAKE_ON=		-DWITH_RUBY:BOOL=ON

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local/include|${LOCALBASE}/include| ; \
		s|/usr/local/lib|${LOCALBASE}/lib| ; \
		/$${DOCUMENTATION_FILES}/s|^|#|' ${WRKSRC}/CMakeLists.txt

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${TAR} -C ${WRKSRC}/examples --exclude "*Makefile*" -cf - . | \
		${TAR} -C ${STAGEDIR}${EXAMPLESDIR} --unlink -xf -
	@${CHMOD} -R a+rX ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
