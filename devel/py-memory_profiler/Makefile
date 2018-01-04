# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	memory_profiler
PORTVERSION=	0.47
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	johannes@perceivon.net
COMMENT=	Line-by-line and process memory consumption analysis

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	PSUTIL
OPTIONS_DEFAULT=	PSUTIL

PSUTIL_DESC=	Use psutil for better performance
PSUTIL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>1.0.0:sysutils/py-psutil@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
