# New ports collection makefile for:	ko-pycodec
# Date created:		29 April 2001
# Whom:			Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	pycodec
PORTVERSION=	2.0.4
PORTEPOCH=	1
CATEGORIES=	korean python converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	koco
DISTNAME=	KoreanCodecs-${PORTVERSION}

MAINTAINER=	perky@fallin.lv

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PLIST_SUB+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR:S,^${LOCALBASE}/,,g}

.include <bsd.port.mk>
