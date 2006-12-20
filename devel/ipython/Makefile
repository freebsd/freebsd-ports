# Ports collection makefile for:	IPython
# Date created:				Nov, 13	2003
# Whom:					Dryice Liu
#
# $FreeBSD$
#

PORTNAME=	ipython
PORTVERSION=	0.7.3
CATEGORIES=	devel python
MASTER_SITES=	http://ipython.scipy.org/dist/ \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	dryice@dryice.name
COMMENT=	An enhanced Interactive Python shell

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pexpect.py:${PORTSDIR}/misc/py-pexpect

MAN1=		ipython.1 pycolor.1
MANCOMPRESSED=	yes

PORTDOCS=	*

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} < 500000
BROKEN=		Coredump during build on alpha 4.x
.endif

.include <bsd.port.post.mk>
