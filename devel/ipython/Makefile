# Ports collection makefile for:	IPython
# Date created:				Nov, 13	2003
# Whom:					Dryice Liu
#
# $FreeBSD$
#

PORTNAME=	ipython
PORTVERSION=	0.8.0
CATEGORIES=	devel python
MASTER_SITES=	http://ipython.scipy.org/dist/ \
		${MASTER_SITE_LOCAL} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	dryice
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	An enhanced Interactive Python shell

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pexpect.py:${PORTSDIR}/misc/py-pexpect

MAN1=		ipython.1 pycolor.1
MANCOMPRESSED=	yes

PORTDOCS=	*

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 250
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_ctypes.so:${PORTSDIR}/devel/py-ctypes
.endif

.include <bsd.port.post.mk>
