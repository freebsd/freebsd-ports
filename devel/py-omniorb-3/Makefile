# Created by: Johann Visagie <johann@egenetics.com>
# $FreeBSD$

PORTNAME=	omniorb
PORTVERSION=	3.7
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/omniORBpy/omniORBpy-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	3
DISTNAME=	omniORBpy-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python bindings for omniORB4, a CORBA 2.6 ORB

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

DEPRECATED=	Uses legacy version of omniORB, consider using devel/py-omniorb
EXPIRATION_DATE=2019-01-31

LIB_DEPENDS=	libomniORB4.so:devel/omniORB-4.1
# parts of omniORB4 source tree is required to build omniORBpy;
# see also the "post-extract" target below.
BUILD_DEPENDS=	${NONEXISTENT}:devel/omniORB-4.1:patch

USES=		gmake python:2.7 shebangfix ssl tar:bzip2

CONFLICTS=	${PYTHON_PKGNAMEPREFIX}orbit-2* ${PYTHON_PKGNAMEPREFIX}omniorb-4.2*

OPTIONS_DEFINE=	DOCS EXAMPLES

PLIST_SUB=	SONUM=${PORTVERSION:C/.*\.//}

OMNIORB_WRKSRC!=	cd ${.CURDIR}/../omniORB-4.1 && ${MAKE} -V WRKSRC

GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
MAKEFILE=	GNUmakefile
#USE_LDCONFIG=	yes
SHEBANG_FILES=	examples/tests/*.py examples/poa/*.py \
		examples/fortune/*.py examples/embed/*.py \
		examples/valuetype/tests/*.py \
		examples/valuetype/simple/*.py \
		examples/tictactoe/*.py \
		examples/echo/*.py \
		examples/weather/*.py \
		examples/random/*.py

CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD}
CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE} --with-omniorb=${LOCALBASE}

pre-configure:
	cd ${OMNIORB_WRKSRC} && ${FIND} idl | ${CPIO} --quiet -pdum ${WRKSRC}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/*.so
	${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/omniidl_be/__init__.py
	cd ${STAGEDIR}${PYTHON_SITELIBDIR} && ${PYTHON_CMD} -c "import py_compile;py_compile.compile('CosNaming/__init__.py',None,'CosNaming/__init__.pyc',True)"
	cd ${STAGEDIR}${PYTHON_SITELIBDIR} && ${PYTHON_CMD} -c "import py_compile;py_compile.compile('CosNaming__POA/__init__.py',None,'CosNaming__POA/__init__.pyc',True)"
	cd ${STAGEDIR}${PYTHON_SITELIBDIR} && ${PYTHON_CMD} -c "import py_compile;py_compile.compile('omniidl_be/python.py',None,'omniidl_be/python.pyc',True)"

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/tex
	${INSTALL_DATA} ${WRKSRC}/doc/omniORBpy.* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/omniORBpy/* ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/tex/* ${STAGEDIR}${DOCSDIR}/tex

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${FIND} . \
	  | ${CPIO} --quiet -pdum -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
