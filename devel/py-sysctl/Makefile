# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sysctl
PORTVERSION=	0.1b3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Wrapper for the sysctl system functions

LICENSE=	BSD

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 320
.include "${PORTSDIR}/devel/py-virtualenv/files/py3k-fix-pkg-plist.inc"
.endif

.include <bsd.port.post.mk>
