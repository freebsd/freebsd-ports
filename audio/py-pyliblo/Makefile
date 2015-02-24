# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pyliblo
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	http://das.nasophon.de/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python wrapper for the Liblo OSC Library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	pyrex>=0.9.4:${PORTSDIR}/devel/pyrex
LIB_DEPENDS=	liblo.so:${PORTSDIR}/audio/liblo

USES=		python
USE_PYTHON=	distutils
MAKE_ENV+=	PREFIX=${PREFIX} LOCALBASE=${LOCALBASE}
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's#%%LOCALBASE%%#${LOCALBASE}#g' ${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/liblo.so
	${INSTALL_MAN} ${WRKSRC}/scripts/dump_osc.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/scripts/send_osc.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/API.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/examples.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
