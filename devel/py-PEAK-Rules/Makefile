# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	PEAK-Rules
PORTVERSION=	0.5a1
PORTREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	LOCAL/wen
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}.dev-r2686

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Generic functions and business rules support systems

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Extremes>=1.1.1:${PORTSDIR}/devel/py-extremes \
		${PYTHON_PKGNAMEPREFIX}AddOns>=0.6:${PORTSDIR}/devel/py-AddOns \
		${PYTHON_PKGNAMEPREFIX}BytecodeAssembler>0:${PORTSDIR}/devel/py-BytecodeAssembler
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
