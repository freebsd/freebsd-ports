# ex:ts=8
# Ports collection makefile for:	py-istring
# Date created:			Apr 28, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	istring
PORTVERSION=	1.0.1
CATEGORIES=	devel python
MASTER_SITES=	http://www.neosynapse.net/downloads/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interpolated Strings

IGNORE=		port does not install the necessary classes to run
DEPRECATED=	port is unmaintained and broken
EXPIRATION_DATE=2011-08-17

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
