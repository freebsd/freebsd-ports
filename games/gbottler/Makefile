# New ports collection makefile for:	gbottler
# Date created:				3 Apr 2004
# Whom:					UMENO Takashi
#
# $FreeBSD$
#

PORTNAME=	gbottler
PORTVERSION=	0.0.3
CATEGORIES=	games
MASTER_SITES=	http://callisto.comlab.soft.iwate-pu.ac.jp/~g031y177/etc/files/gbottler/

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	SSTP Bottle client

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/japanese.pth:${PORTSDIR}/japanese/pycodec

PLIST_SUB=	VERSION=${PORTVERSION}

USE_PYTHON=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
