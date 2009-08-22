# New ports collection makefile for:	py-psyco
# Date created:		5 September 2002
# Whom:			Alex Rodioukov <simuran@shaw.ca>
#
# $FreeBSD$
#

PORTNAME=	psyco
PORTVERSION=	1.6
CATEGORIES=	devel python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python Specializing Compiler

ONLY_FOR_ARCHS=	i386

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

WRKSRC=		${WRKDIR}/psyco-${PORTVERSION}

post-install:
# permission safeness
	@${CHMOD} -R ${SHAREMODE} ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/
	@${CHMOD} -R a+X ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/

.include <bsd.port.mk>
