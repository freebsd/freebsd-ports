# New ports collection makefile for:	py-serial
# Date created:		26 February 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	serial
PORTVERSION=	1.12
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pyserial
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyserial-${PORTVERSION}

MAINTAINER=	perky@fallin.lv

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-a
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S,^${LOCALBASE}/,,g}
SETUP_CMD=	cd ${WRKSRC} && ${PYTHON_CMD} setup.py

do-build:
	${SETUP_CMD} build

do-install:
	${SETUP_CMD} install

.include <bsd.port.mk>
