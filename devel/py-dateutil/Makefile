# New ports collection makefile for:	py-datetime
# Date created:		Sun May  8 06:34:45 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dateutil
PORTVERSION=	0.9
CATEGORIES=	devel python
MASTER_SITES=	https://moin.conectiva.com.br/DateUtil?action=AttachFile&do=get&target=
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-dateutil-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Provides powerful extensions to the standard datetime module

USE_BZIP2=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

FETCH_BEFORE_ARGS=	-o ${DISTNAME}${EXTRACT_SUFX}

.include <bsd.port.mk>
