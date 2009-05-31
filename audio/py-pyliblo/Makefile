# New ports collection makefile for:	py-pyliblo
# Date created:		2009-01-25
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pyliblo
PORTVERSION=	0.7.2
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	http://das.nasophon.de/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Python wrapper for the Liblo OSC Library

BUILD_DEPENDS=	pyrex>=0.9.4:${PORTSDIR}/devel/pyrex
LIB_DEPENDS=	lo.7:${PORTSDIR}/audio/liblo

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
MAKE_ENV+=		PREFIX=${PREFIX} LOCALBASE=${LOCALBASE} \
			LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	dump_osc.1 send_osc.1

post-patch:
	${REINPLACE_CMD} -e 's#%%LOCALBASE%%#${LOCALBASE}#g' ${WRKSRC}/setup.py

post-install:
	${INSTALL_MAN} ${WRKSRC}/scripts/dump_osc.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/scripts/send_osc.1 ${PREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/API.html ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/examples.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
