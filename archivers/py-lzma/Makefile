# New ports collection makefile for:	py-lzma
# Date created:		28 May 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	lzma
PORTVERSION=	0.0.3
CATEGORIES=	archivers python
MASTER_SITES=	http://www.joachim-bauch.de/projects/python/pylzma/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pylzma-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python binding for the LZMA compression library

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_REINPLACE=	yes

post-patch:
	${FIND} ${WRKSRC} -name '*.cpp' -or -name '*.c' -or \
		-name '*.h' | ${XARGS} -n1 ${REINPLACE_CMD} 's///g'

.include <bsd.port.mk>
