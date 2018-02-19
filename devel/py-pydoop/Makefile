# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pydoop
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Python interface to Hadoop

BUILD_DEPENDS=	${LOCALBASE}/bin/yarn:devel/hadoop2
RUN_DEPENDS=	${LOCALBASE}/bin/yarn:devel/hadoop2

USES=		python:2.7
USE_PYTHON=	distutils autoplist
USE_JAVA=	1.7
MAKE_ENV+=	HADOOP_HOME=${LOCALBASE} \
		JAVA_HOME=${JAVA_HOME}

.include <bsd.port.mk>
