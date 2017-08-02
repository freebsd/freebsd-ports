# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cli-helpers
PORTVERSION=	0.2.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	cli_helpers-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Helpers for building command-line apps

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygments>=1.6:textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}terminaltables>=3.0.0:textproc/py-terminaltables

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils
USES=		python

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.csv>=1.0.0:devel/py-backports.csv
.endif

.include <bsd.port.post.mk>
