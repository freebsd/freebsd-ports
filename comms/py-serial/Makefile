# New ports collection makefile for:	py-serial
# Date created:		26 February 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	serial
PORTVERSION=	2.1
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pyserial
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyserial-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Serial port encapsulation library for Python

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-a
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

.include <bsd.port.mk>
