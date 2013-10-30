# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	memoryprofiler
PORTVERSION=	0.29
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	memory_profiler-${PORTVERSION}

MAINTAINER=	xmj@chaot.net
COMMENT=	Line-by-line and process memory consumption analysis

LICENSE=	BSD

OPTIONS_DEFINE=	PSUTIL
PSUTIL_DESC=	Use psutil for better performance
PSUTIL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}-psutil>0:${PORTSDIR}/sysutils/py-psutil

OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	memory_profiler
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
