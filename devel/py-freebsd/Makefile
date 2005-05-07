# Ports collection makefile for:	py-freebsd
# Date created:		14 June 2002
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	freebsd
PORTVERSION=	0.9.1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~perky/distfiles/
MASTER_SITE_SUBDIR=	perky
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-freebsd-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Python interface to FreeBSD-specific system libraries

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/freebsd.so \
		%%PYTHON_SITELIBDIR%%/freebsd_compat02.py \
		%%PYTHON_SITELIBDIR%%/freebsd_compat02.pyc \
		%%PYTHON_SITELIBDIR%%/freebsd_compat02.pyo

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		requires GEOM which is only present on FreeBSD 5.x and above
.endif

.include <bsd.port.post.mk>
