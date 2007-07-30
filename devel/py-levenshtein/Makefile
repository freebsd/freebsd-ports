# New ports collection makefile for:	py-levenshtein
# Date created:				30 August 2006
# Whom:					Aron Stansvik <elvstone@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	levenshtein
PORTVERSION=	0.10.1
CATEGORIES=	devel python
MASTER_SITES=	http://trific.ath.cx/Ftp/python/levenshtein/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	perky
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-Levenshtein-${PORTVERSION}

MAINTAINER=	elvstone@gmail.com
COMMENT=	Python extension computing string distances and similarities

WRKSRC=		${WRKDIR}/python-Levenshtein-${PORTVERSION}

USE_PYTHON=	2.2+
USE_PYTHON_PREFIX=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	python-Levenshtein

.include <bsd.port.mk>
