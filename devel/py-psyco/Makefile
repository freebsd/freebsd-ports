# New ports collection makefile for:	py-psyco
# Date created:		5 September 2002
# Whom:			Alex Rodioukov <simuran@shaw.ca>
#
# $FreeBSD$
#

PORTNAME=	psyco
PORTVERSION=	1.1.1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	psyco
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	simuran@shaw.ca
COMMENT=	Python Specializing Compiler

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

WRKSRC=		${WRKDIR}/psyco-${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
