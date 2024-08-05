PORTNAME=	biosig
DISTVERSION=	2.6.1
CATEGORIES=	biology
MASTER_SITES=	SF/${PORTNAME}/BioSig%20for%20C_C%2B%2B/src/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for reading and writing different biosignal data format
WWW=		https://biosig.sourceforge.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../../COPYING

BUILD_DEPENDS=	${PYNUMPY}
LIB_DEPENDS=	libbiosig.so:biology/biosig

USES=		python tar:xz
USE_PYTHON=	distutils autoplist

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
WRKSRC_SUBDIR=	biosig4c++/python

post-patch:
	cd ${WRKSRC} && \
		${SED} -e 's|@PACKAGE_VERSION@|${DISTVERSION}|' < setup.py.in > setup.py && \
		${TOUCH} README.md

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/biosig${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
