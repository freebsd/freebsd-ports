# New ports collection makefile for:	py-kyotocabinet
# Date created:		2011-08-25
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kyotocabinet
PORTVERSION=	1.20
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://fallabs.com/${PORTNAME}/pythonpkg/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding of kyotocabinet

LIB_DEPENDS=	kyotocabinet:${PORTSDIR}/databases/kyotocabinet

USE_PYTHON=	3.1+
USE_PYDISTUTILS=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/${PORTNAME}.so
PYDISTUTILS_EGGINFO=	Kyoto_Cabinet-1.5-py${PYTHON_VER}.egg-info

.include <bsd.port.mk>
