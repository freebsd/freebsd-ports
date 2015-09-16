# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	memoryprofiler
PORTVERSION=	0.31
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	memory_profiler-${PORTVERSION}

MAINTAINER=	xmj@chaot.net
COMMENT=	Line-by-line and process memory consumption analysis

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	PSUTIL
PSUTIL_DESC=	Use psutil for better performance
PSUTIL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>1.0.0:${PORTSDIR}/sysutils/py-psutil

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
