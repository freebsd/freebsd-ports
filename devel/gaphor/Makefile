# New ports collection makefile for:	gaphor
# Date created:        06 August 2003
# Whom:                rehsack@liwing.de
#
# $FreeBSD$
#

PORTNAME=	gaphor
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DIST_SUBDIR=	gnome2

MAINTAINER=	rehsack@liwing.de
COMMENT=	UML modeling environment written in Python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/diacanvas/_canvasmodule.so:${PORTSDIR}/graphics/diacanvas2
RUN_DEPENDS=	${BUILD_DEPENDS}
.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	Xvfb:${X_VFBSERVER_PORT}
.endif

BROKEN=		Does not build with python 2.4
USE_PYTHON=	2.2+

do-configure:
	@cd ${WRKSRC}; ${PYTHON_CMD} setup.py config

do-build:
	@cd ${WRKSRC}; ${PYTHON_CMD} setup.py build; ${PYTHON_CMD} setup.py build_mo

do-install:
	@cd ${WRKSRC}; ${PYTHON_CMD} setup.py install --install-data=${PREFIX}/share/gaphor; ${PYTHON_CMD} setup.py install_mo

.include <bsd.port.mk>
