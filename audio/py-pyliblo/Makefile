# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pyliblo
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	http://das.nasophon.de/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A Python wrapper for the Liblo OSC Library

BUILD_DEPENDS=	pyrex>=0.9.4:${PORTSDIR}/devel/pyrex
LIB_DEPENDS=	liblo.so:${PORTSDIR}/audio/liblo

USE_PYTHON=		yes
NO_STAGE=	yes
USE_PYDISTUTILS=	yes
MAKE_ENV+=		PREFIX=${PREFIX} LOCALBASE=${LOCALBASE}
LDFLAGS+=		-L${LOCALBASE}/lib

MAN1=	dump_osc.1 send_osc.1

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's#%%LOCALBASE%%#${LOCALBASE}#g' ${WRKSRC}/setup.py

post-install:
	${INSTALL_MAN} ${WRKSRC}/scripts/dump_osc.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/scripts/send_osc.1 ${PREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/API.html ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/examples.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
