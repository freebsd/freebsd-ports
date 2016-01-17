# Created by: Hye-Shik Chang <perky@fallin.lv>
# $FreeBSD$

PORTNAME=	pqueue
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://www.csse.monash.edu.au/hons/projects/1999/Andrew.Snare/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PQueue-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fibonacci-Heap based Priority-Queue Extension for Python

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python tar:bzip2
USE_PYTHON=	distutils autoplist

WRKSRC=		${WRKDIR}/PQueue

post-patch:
	${CP} ${FILESDIR}/setup.py ${WRKSRC}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/pqueue.so

.include <bsd.port.mk>
