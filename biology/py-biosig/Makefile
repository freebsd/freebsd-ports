PORTNAME=	biosig
DISTVERSION=	3.9.8
CATEGORIES=	biology
MASTER_SITES=	SF/${PORTNAME}/BioSig%20for%20C_C%2B%2B/src/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for reading and writing different biosignal data format
WWW=		https://biosig.sourceforge.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../../COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
LIB_DEPENDS=	libbiosig.so:biology/biosig

USES=		python tar:xz
USE_PYTHON=	distutils autoplist

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
WRKSRC_SUBDIR=	biosig4c++/python

post-patch: # substitute values in setup.py.in and create empty README.md to avoid error during build
	@cd ${WRKSRC} && \
		${SED} -e 's|@PACKAGE_VERSION@|${DISTVERSION}|g' \
		    -e "s|include_dirs = \[numpy.get_include()\]|include_dirs = [numpy.get_include(), '${LOCALBASE}/include']|" \
		    -e "s|LIBDIRS = \['../', '../lib', './lib'\]|LIBDIRS = ['${LOCALBASE}/lib', '../', '../lib', './lib']|" \
		    < setup.py.in > setup.py && \
		${TOUCH} README.md

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/biosig${PYTHON_TAG}.so

.include <bsd.port.mk>
