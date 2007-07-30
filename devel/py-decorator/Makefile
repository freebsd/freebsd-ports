# New ports collection makefile for:	py-decorator
# Date created:		Thu Jun 21 14:49:52 MSD 2007
# Whom:			Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	decorator
PORTVERSION=	2.0.1
CATEGORIES=	devel python
MASTER_SITES=	http://www.phyast.pitt.edu/~micheles/python/ \
		http://pylonshq.com/download/0.9.5/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dsh@vlink.ru
COMMENT=	Better living through Python with decorators

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install
USE_ZIP=	yes

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
PORTDOCS=	documentation.*

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
