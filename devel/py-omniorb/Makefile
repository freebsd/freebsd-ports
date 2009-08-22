# New ports collection makefile for:	py-omniorb
# Date created:		14 November 2000
# Whom:			Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	omniorb
PORTVERSION=	3.3
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/omniORBpy/omniORBpy%20${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	omniORBpy-${PORTVERSION}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Python bindings for omniORB4, a CORBA 2.6 ORB

LIB_DEPENDS=	omniORB4.1:${PORTSDIR}/devel/omniORB
RUN_DEPENDS=	omniidl:${PORTSDIR}/devel/omniORB
# parts of omniORB4 source tree is required to build omniORBpy;
# see also the "post-extract" target below.
BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/omniORB:patch

CONFLICTS=	py*-orbit-2*

PLIST_SUB+=	SONUM=${PORTVERSION:C/.*\.//}

CONFIGURE_WRKSRC=	${WRKSRC}/build
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}
OMNIORB_WRKSRC!=	cd ${.CURDIR}/../omniORB && ${MAKE} -V WRKSRC

USE_PYTHON=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
USE_LDCONFIG=	yes

CONFIGURE_SCRIPT=	../configure
CONFIGURE_ENV+=	CC=${CC} CFLAGS="${CFLAGS}" CXX=${CXX} CXXFLAGS="${CXXFLAGS}" \
		CPP=${CPP} PYTHON=${PYTHON_CMD}
CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE} --with-omniorb=${LOCALBASE}

pre-configure:
	@${MKDIR} ${CONFIGURE_WRKSRC}
	@cd ${OMNIORB_WRKSRC} && ${FIND} idl | ${CPIO} --quiet -pdum ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -Ee 's#-pthread|-lc_r#${PTHREAD_LIBS}#' \
		${WRKSRC}/mk/beforeauto.mk.in

pre-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
	@${MKDIR} ${DOCSDIR}/tex
	@${INSTALL_DATA} ${WRKSRC}/doc/omniORBpy.* ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/omniORBpy/* ${DOCSDIR}/html
	@${INSTALL_DATA} ${WRKSRC}/doc/tex/* ${DOCSDIR}/tex
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${FIND} . \
	  | ${CPIO} --quiet -pdum -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

post-install:
	@${PYTHON_CMD} -c "import py_compile;py_compile.compile('${PYTHON_SITELIBDIR}/CosNaming/__init__.py',None,'${PYTHON_SITELIBDIR}/CosNaming/__init__.pyc',True)"
	@${PYTHON_CMD} -c "import py_compile;py_compile.compile('${PYTHON_SITELIBDIR}/CosNaming__POA/__init__.py',None,'${PYTHON_SITELIBDIR}/CosNaming__POA/__init__.pyc',True)"
	@${PYTHON_CMD} -c "import py_compile;py_compile.compile('${PYTHON_SITELIBDIR}/omniidl_be/python.py',None,'${PYTHON_SITELIBDIR}/omniidl_be/python.pyc',True)"

.include <bsd.port.mk>
