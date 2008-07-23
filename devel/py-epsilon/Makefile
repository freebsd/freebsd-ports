# New ports collection makefile for:	py-epsilon
# Date created:				10 Apr 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	epsilon
PORTVERSION=	0.5.7
CATEGORIES=	devel python
MASTER_SITES=	http://divmod.org/trac/attachment/wiki/SoftwareReleases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Epsilon-${PORTVERSION}
EXTRACT_SUFX=	.tar.gz?format=raw

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Epsilon is a set of Python utility modules used by DivMod projects

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Epsilon
USE_TWISTED=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
