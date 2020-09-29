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

PYTHON_BUILD_DEPENDS=	swig:devel/swig
PYTHON_CMAKE_BOOL=	WITH_PYTHON
PYTHON_USES=		python
RUBY_BUILD_DEPENDS=	swig:devel/swig
RUBY_CMAKE_BOOL=	WITH_RUBY
RUBY_USE=		ruby=yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/CMakeLists.txt

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} '! -name *Makefile*'

.include <bsd.port.mk>
