# ex:ts=8
# New ports collection makefile for:	ftpcube
# Date created:			Dec 13, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ftpcube
PORTVERSION=	0.2.0
CATEGORIES=	ftp python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk.py:${PORTSDIR}/x11-toolkits/py-gtk

USE_PYTHON=	yes

SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py

do-build:
	@${SETUP_CMD} build

do-install:
	@${SETUP_CMD} install

.include <bsd.port.mk>
