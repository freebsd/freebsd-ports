# New ports collection makefile for:	gaphor
# Date created:        06 August 2003
# Whom:                rehsack@liwing.de
#
# $FreeBSD$
#

PORTNAME=	gaphor
PORTVERSION=	0.7.0.1
PORTREVISION=	1
#PORTREVISION=	1
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

USE_PYTHON=	2.2+
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/\\.[0-9]+$//}

do-configure:
	@cd ${WRKSRC}; ${PYTHON_CMD} setup.py config

do-build:
	@cd ${WRKSRC}; ${PYTHON_CMD} setup.py build; ${PYTHON_CMD} setup.py build_mo

do-install:
	@cd ${WRKSRC}; ${PYTHON_CMD} setup.py install --install-data=${PREFIX}/share/gaphor; ${PYTHON_CMD} setup.py install_mo
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}

.include <bsd.port.mk>
