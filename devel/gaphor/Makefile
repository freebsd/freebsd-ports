# New ports collection makefile for:	gaphor
# Date created:        06 August 2003
# Whom:                rehsack@liwing.de
#
# $FreeBSD$
#

PORTNAME=	gaphor
PORTVERSION=	0.4.0
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DIST_SUBDIR=	gnome2

MAINTAINER=	rehsack@liwing.de
COMMENT=	UML modeling environment written in Python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/diacanvas/_canvasmodule.so:${PORTSDIR}/graphics/diacanvas2
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.2+

.if !defined(DISPLAY)
BUILD_DEPENDS+=	Xvfb:${X_VFBSERVER_PORT}
DISPLAYHACK=	localhost:1001
.endif

do-configure:
.if exists(${WRKDIR}/.Xvfb.pid)
	@-${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill
	@${RM} -f ${WRKDIR}/.Xvfb.pid
.endif
.if !defined(DISPLAY)
	#
	# This is a UGLY hack to not have to specify a X-Display.
	#
	${X11BASE}/bin/Xvfb :1001 -screen 0 800x600x24 > /dev/null 2>&1 & ${ECHO} $$! > ${WRKDIR}/.Xvfb.pid
	@sleep 5
	@cd ${WRKSRC}; ${ENV} DISPLAY=${DISPLAYHACK} ${PYTHON_CMD} setup.py config
	@-${CAT} ${WRKDIR}/.Xvfb.pid | ${XARGS} kill
	@${RM} -f ${WRKDIR}/.Xvfb.pid
.else
	@cd ${WRKSRC}; ${PYTHON_CMD} setup.py config
.endif

do-build:
	@cd ${WRKSRC}; ${PYTHON_CMD} setup.py build; ${PYTHON_CMD} setup.py build_mo

do-install:
	@cd ${WRKSRC}; ${PYTHON_CMD} setup.py install --install-data=${PREFIX}/share/gaphor; ${PYTHON_CMD} setup.py install_mo

.include <bsd.port.mk>
