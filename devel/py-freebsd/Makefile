# Ports collection makefile for:	py-freebsd
# Date created:		14 June 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	freebsd
PORTVERSION=	0.2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	perky
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-freebsd-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python interface to FreeBSD-specific system libraries

PLIST_FILES=	lib/%%PYTHON_VERSION%%/site-packages/freebsd.so
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
