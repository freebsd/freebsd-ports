# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	rrdtool_lgpl
PORTVERSION=	1.0b1
PORTREVISION=	6
CATEGORIES=	databases python
MASTER_SITES=	SF/py-rrdtool/py-rrdtool/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-rrdtool-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python interface to RRDTool, the graphing and logging utility

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	librrd.so:databases/rrdtool

USES=		python:2
USE_PYTHON=	distutils autoplist

LIBDIR?=	${LOCALBASE}/lib # directory where librrd.so lives

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_rrdtool.so

.include <bsd.port.mk>
