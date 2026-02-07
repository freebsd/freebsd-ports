PORTNAME=	cxxtest
PORTVERSION=	4.4
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF:DEFAULT \
		https://github.com/CxxTest/cxxtest.github.com/raw/8505a9c37bdf17d9167f0b946c82ccb032d3cd4c/:docs
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Simple and powerful JUnit/CppUnit/xUnit-like framework for C++
#WWW=		http://cxxtest.com/ # unavailable, https://github.com/CxxTest/cxxtest/issues/157
#WWW=		https://github.com/CxxTest/cxxtest.github.com
WWW=		https://github.com/CxxTest/cxxtest

LICENSE=	LGPL3+

USES=		gmake python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=0:devel/py-ply@${PY_FLAVOR}
BUILD_DEPENDS=	${RUN_DEPENDS}

USE_PYTHON=	autoplist distutils noflavors
BINARY_ALIAS=	c++=${CXX} cl=${FALSE} clang++=${FALSE} g++=${FALSE}
NO_ARCH=	yes

WRKSRC_SUBDIR=		python

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_DEFAULT=	DOCS EXAMPLES

DOCS_DISTFILES=		guide.pdf:docs
DOCS_PORTDOCS=		*
EXAMPLES_PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/cxxtest
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/cxxtest/* \
		${STAGEDIR}${PREFIX}/include/cxxtest/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/guide.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/guide.txt ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	( cd ${WRKSRC}/../sample/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR} )

do-test:
	( set -x \
		&& cd ${WRKSRC}/../test \
		&& ${RM} -R test_cxxtest \
		&& ${PYTHON_CMD} -m venv test_cxxtest --system-site-packages --without-pip \
		&& . test_cxxtest/bin/activate \
		&& ( cd ../python && ${PYTHON_CMD} setup.py install --prefix "$$VIRTUAL_ENV" ) \
		&& ${SETENV} "PATH=${PATH}" ${PYTHON_CMD} test_cxxtest.py --verbose \
	)

.include <bsd.port.mk>
