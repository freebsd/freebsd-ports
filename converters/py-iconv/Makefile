# New ports collection makefile for:	py-iconv
# Date created:		11 September 2001
# Whom:			Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$

PORTNAME=	iconv
PORTVERSION=	0.1.2
CATEGORIES=	converters python
MASTER_SITES=	http://www.mx1.ru/iconv/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	perky@python.or.kr

BUILD_DEPENDS=	${PYDISTUTILS}
LIB_DEPENDS=	iconv.2:${PORTSDIR}/converters/iconv

USE_PYTHON=	yes
SETUP_CMD=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py
PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S|^${LOCALBASE}/||g}

do-build:
	${SETUP_CMD} build

do-install:
	${SETUP_CMD} install

.include <bsd.port.mk>
