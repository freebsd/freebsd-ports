# New ports collection makefile for:	py-isodate
# Date created:		2012-02-07
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	isodate
PORTVERSION=	0.4.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	An ISO 8601 date/time/duration parser and formater

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|setuptools|do_not_use_&|' ${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
