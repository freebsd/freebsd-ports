# New ports collection makefile for:	sip
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@home.com
#
# $FreeBSD$
#

PORTNAME=	sip
PORTVERSION=	3.7
CATEGORIES=	devel python
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/sip/
DISTNAME=	sip-x11-gpl-${PORTVERSION}

MAINTAINER=	osgene@web.de
COMMENT=	Python to C++ bindings generator

USE_PYTHON=	yes
USE_QT_VER=	3
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=	yes

ALL_TARGET=	all install

do-configure:
	@${MKDIR} ${WRKDIR}/headers ${WRKDIR}/binaries ${WRKDIR}/modules
	@( cd ${WRKSRC} && ${ECHO} "yes" | ${PYTHON_CMD} build.py \
		-q ${X11BASE} -e ${WRKDIR}/headers \
		-b ${WRKDIR}/binaries -d ${WRKDIR}/modules )

do-install:
	${CP} -Rf ${WRKDIR}/modules/* ${PREFIX}/lib/
	${MKDIR} ${PREFIX}/include/sip
	${CP} ${WRKDIR}/headers/* ${PREFIX}/include/sip/
	${CP} ${WRKDIR}/binaries/* ${PREFIX}/bin/

.include <bsd.port.mk>
