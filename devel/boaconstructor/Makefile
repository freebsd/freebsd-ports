# New ports collection makefile for:    boa-constructor
# Date created:         		15 December 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	boaconstructor
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	boa-constructor
DISTNAME=	boa-constructor-${PORTVERSION}.src

MAINTAINER=	filippo@widestore.net
COMMENT=	A cross platform RAD GUI Building IDE for wxPython

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/wxPython/wxc.so:${PORTSDIR}/x11-toolkits/py-wxPython

WRKSRC=		${WRKDIR}/boa-constructor-${PORTVERSION}

USE_ZIP=	yes
USE_PYTHON=	yes
DATADIR=	${PREFIX}/share/Boa

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -x zoa ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -x zoa ${WRKSRC}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/py_compile.py ${WRKSRC}/ZopeLib/zoa/breakpoint.py
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/py_compile.py ${WRKSRC}/ZopeLib/zoa/breakpoint.py

do-install:
	@${MKDIR} ${DATADIR}
	@${TAR} cCf ${WRKSRC} - --exclude "*.orig" . | ${TAR} xUCf ${DATADIR} -
	@printf "#!/bin/sh\n${PYTHON_CMD} ${DATADIR}/Boa.py\n" \
		> ${WRKDIR}/Boa.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/Boa.sh ${PREFIX}/bin/Boa

.include <bsd.port.mk>
