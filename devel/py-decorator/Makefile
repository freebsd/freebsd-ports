# New ports collection makefile for:	py-decorator
# Date created:		Thu Jun 21 14:49:52 MSD 2007
# Whom:			Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	decorator
PORTVERSION=	3.1.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dsh@wizard.volgograd.ru
COMMENT=	Better living through Python with decorators

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/documentation.* ${DOCSDIR}
.endif

.include <bsd.port.mk>
