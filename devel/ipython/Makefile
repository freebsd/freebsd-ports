# Ports collection makefile for:	IPython
# Date created:				Nov, 13	2003
# Whom:					Dryice Liu
#
# $FreeBSD$
#

PORTNAME=	ipython
PORTVERSION=	0.6.15
CATEGORIES=	devel python
MASTER_SITES=	http://ipython.scipy.org/dist/ \
		http://bsdchat.com/dist/dryice/
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	dryice@liu.com.cn
COMMENT=	An enhanced Interactive Python shell

MAN1=		ipython.1 pycolor.1
MANCOMPRESSED=	yes

USE_PYTHON=	2.2+
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} < 500000
BROKEN=		"Coredump during build on alpha 4.x"
.endif

.include <bsd.port.post.mk>
