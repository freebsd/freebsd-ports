# New ports collection makefile for:	py-cjkcodecs
# Date created:		6 June 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	cjkcodecs
PORTVERSION=	1.1.1
CATEGORIES=	converters python
MASTER_SITES=	http://download.berlios.de/cjkpython/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python Unicode Codecs for Chinese, Japanese and Korean encodings

USE_PYTHON=	2.1+
USE_PYDISTUTILS=	yes

post-install:
	@${STRIP_CMD} ${PYTHON_SITELIBDIR}/cjkcodecs/*.so

.include <bsd.port.mk>
