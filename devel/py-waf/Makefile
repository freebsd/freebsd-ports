# New ports collection makefile for:	py-waf
# Date created:				2009-04-29
# Whom:					Olivier Duchateau <duchateau.olivier@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	waf
PORTVERSION=	1.5.15
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	duchateau.olivier@gmail.com
COMMENT=	Python-based build system

USE_BZIP2=	yes
USE_PYTHON=	yes

pre-configure:
	@cd ${WRKSRC} && ${PYTHON_CMD} waf-light --make-waf && ${TRUE}

do-build:
	@cd ${WRKSRC} && ${PYTHON_CMD} waf configure --prefix=${LOCALBASE} && ${TRUE}

do-install:
	@cd ${WRKSRC} && ${PYTHON_CMD} waf install --yes && ${TRUE}

.include <bsd.port.mk>
