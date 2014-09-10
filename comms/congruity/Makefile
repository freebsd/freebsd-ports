# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	congruity
PORTVERSION=	18
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	SF

MAINTAINER=	shurd@FreeBSD.org
COMMENT=	GUI Logitech Harmony configuration tool

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libconcord>=0:${PORTSDIR}/comms/py-libconcord

MAKE_ARGS=	MANDIR=${PREFIX}/man
USES=		tar:bzip2 gmake desktop-file-utils
USE_PYTHON=	2.7+
USE_WX=		2.8+
WANT_UNICODE=	yes
WX_COMPS=	python

.include <bsd.port.mk>
