# ex:ts=8
# Ports collection makefile for:	py-ciphon
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ciphon
PORTVERSION=	0.4.0
CATEGORIES=	devel python
MASTER_SITES=	SF/pythonsiphon/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	xride@FreeBSD.org
COMMENT=	A module for python that adds cpan-like functionality

RUN_DEPENDS=	${PYEXPAT}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
	@${MV} -f ${PREFIX}/bin/ciphon.py ${PREFIX}/bin/ciphon

.include <bsd.port.mk>
