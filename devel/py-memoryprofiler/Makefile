# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	memoryprofiler
PORTVERSION=	0.27
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	memory_profiler-${PORTVERSION}

MAINTAINER=	xmj@chaot.net
COMMENT=	Line-by-line and process memory consumption analysis

LICENSE=	BSD

OPTIONS_DEFINE=	PSUTIL
PSUTIL_DESC=	Use psutil for better performance
OPTIONSFILE?=	${PORT_DBDIR}/py-${PORTNAME}/options

NO_STAGE=	yes
.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MPSUTIL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}-psutil>0:${PORTSDIR}/sysutils/py-psutil
.endif

USE_PYTHON=		2.6+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	memory_profiler

PLIST_FILES+=	bin/mprofile \
		%%PYTHON_SITELIBDIR%%/memory_profiler.py \
		%%PYTHON_SITELIBDIR%%/memory_profiler.pyo \
		%%PYTHON_SITELIBDIR%%/memory_profiler.pyc

.include <bsd.port.mk>
