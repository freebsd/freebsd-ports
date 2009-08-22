# ex:ts=8
# Ports collection makefile for:	py-resourcepackage
# Date created:			Feb 17, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	resourcepackage
PORTVERSION=	1.0.0
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20%28final%29
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ResourcePackage-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automated resource-as-package embedding mechanism

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	ResourcePackage

post-install:
	@${FIND} ${PYTHON_SITELIBDIR}/resourcepackage -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/resourcepackage -type d | ${SORT} -r | \
		${SED} "s,^${PREFIX}/,@dirrm ," >> ${TMPPLIST}

.include <bsd.port.mk>
