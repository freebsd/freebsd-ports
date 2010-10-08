# New ports collection makefile for:	py-ptrace
# Date created:		2008-06-15
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ptrace
PORTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-ptrace-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python binding of ptrace

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/distorm.so:${PORTSDIR}/devel/py-distorm

USE_PYTHON=	2.5-2.7
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	python_ptrace
LICENSE=	GPLv2

ONLY_FOR_ARCHS=	i386

post-patch:
	${REINPLACE_CMD} -e 's|libdistorm64.so|${PYTHON_SITELIBDIR}/distorm.so|' \
		${WRKSRC}/ptrace/pydistorm.py

.include <bsd.port.mk>
