# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	cddb
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	audio python
MASTER_SITES=	SF/${PORTNAME}-py/${PORTNAME}-py/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	CDDB-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python module to fetch information on audio CDs from CDDB

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

USES=		python:2.7
USE_PYTHON=	distutils autoplist pythonprefix

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/cdrom.so

.include <bsd.port.mk>
