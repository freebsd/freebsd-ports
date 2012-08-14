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
MASTER_SITES=	APACHE/thrift/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	komarov@valerka.net
COMMENT=	Python interface to Thrift

DISTINFO_FILE=	${.CURDIR}/../thrift/distinfo

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/lib/py

post-patch:
	@${REINPLACE_CMD} -e 's|setuptools|do_not_use_&|' ${WRKSRC}/${PYSETUP}

.include "../thrift/bsd.thrift.mk"
.include <bsd.port.mk>
