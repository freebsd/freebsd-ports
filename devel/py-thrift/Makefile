# New ports collection makefile for:	thrift
# Date created:	   30 Nov 2007
# Whom:		   Jon M. Dugan <jdugan@x1024.net>
#
# $FreeBSD$
#

PORTNAME=	thrift
PORTVERSION=	${THRIFT_PORTVERSION} # to keep in sync with thrift
PORTEPOCH=	1
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=

MAINTAINER=	komarov@valerka.net
COMMENT=	Python interface to Thrift

EXTRACT_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/thrift:extract

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

PLIST_SUB+=		PYDISTUTILS_EGGINFO=${PYDISTUTILS_EGGINFO}
post-extract:
	@${LN} -sfh \
	`cd ${PORTSDIR}/devel/thrift && ${MAKE} -V WRKSRC`/lib/py ${WRKSRC}

do-patch:
	${REINPLACE_CMD} "/name = '/s/Thrift/thrift/" \
	    ${WRKSRC}/setup.py
	${REINPLACE_CMD} "/version = '/s/0\.1/${PORTVERSION}/" \
	    ${WRKSRC}/setup.py

.include "../thrift/bsd.thrift.mk"
.include <bsd.port.mk>
