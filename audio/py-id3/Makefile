# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	id3
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	SF/${PORTNAME}-py/${PORTNAME}-py/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	id3-py_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python module for retrieving and setting ID3 tags on MP3 files

WRKSRC=		${WRKDIR}/id3-py-${PORTVERSION}
USES=		python:2.7
USE_PYTHON=	distutils autoplist pythonprefix

.include <bsd.port.mk>
