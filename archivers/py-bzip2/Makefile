# New ports collection makefile for:	py-bzip2
# Date created:		26 March 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	bzip2
PORTVERSION=	1.1
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	python-bz2
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-bz2-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python Interface for bz2 Compression Library

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/bz2.so
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
