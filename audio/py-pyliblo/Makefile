# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pyliblo
DISTVERSION=	0.10.0
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	http://das.nasophon.de/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python wrapper for the Liblo OSC Library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblo.so:audio/liblo

USES=		python
USE_PYTHON=	distutils concurrent cython
MAKE_ENV+=	PREFIX=${PREFIX} LOCALBASE=${LOCALBASE}

post-patch:
	${REINPLACE_CMD} -e 's#%%LOCALBASE%%#${LOCALBASE}#g' ${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/liblo.so
	${INSTALL_MAN} ${WRKSRC}/scripts/dump_osc.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/scripts/send_osc.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
