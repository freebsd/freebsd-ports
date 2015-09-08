# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pydoop
PORTVERSION=	1.1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Python interface to Hadoop

BUILD_DEPENDS=	${LOCALBASE}/bin/yarn:${PORTSDIR}/devel/hadoop2
RUN_DEPENDS=	${LOCALBASE}/bin/yarn:${PORTSDIR}/devel/hadoop2

USES=		python:2
USE_PYTHON=	distutils
USE_JAVA=	1.7
MAKE_ENV+=	HADOOP_HOME=${LOCALBASE}

.include <bsd.port.mk>
