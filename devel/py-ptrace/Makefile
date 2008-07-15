# New ports collection makefile for:	py-ptrace
# Date created:		2008-06-15
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ptrace
PORTVERSION=	0.3.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Python binding of ptrace

RUN_DEPENDS=	${PYCTYPES} \
		${LOCALBASE}/lib/libdistorm64.so:${PORTSDIR}/devel/distorm

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

ONLY_FOR_ARCHS=	i386

.include <bsd.port.mk>
