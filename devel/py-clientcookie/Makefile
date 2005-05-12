# New ports collection makefile for:	py-clientcookie
# Date created:				Sat Sep  6 14:33:17 PDT 2003
# Whom:					"Richard Kiss" <him@richardkiss.com>
#
# $FreeBSD$
#

PORTNAME=	clientcookie
PORTVERSION=	1.0.3
CATEGORIES=	devel python
MASTER_SITES=	http://wwwsearch.sourceforge.net/ClientCookie/src/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ClientCookie-${PORTVERSION}

MAINTAINER=	him@richardkiss.com
COMMENT=	Client-side HTTP cookies for Python

USE_PYTHON=	2.0+
USE_PYDISTUTILS=	yes

post-install:
	@${FIND} ${PYTHON_SITELIBDIR}/ClientCookie ! -type d | \
		${SED} 's,${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/ClientCookie -type d | ${SORT} -r | \
		${SED} 's,${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
