# New ports collection makefile for:	sip
# Date created:		Sun Oct 17 00:24:28 PDT 1999
# Whom:			adsharma@home.com
#
# $FreeBSD$
#

PORTNAME=	sip
PORTVERSION=	3.4
CATEGORIES=	devel python
MASTER_SITES=	http://www.river-bank.demon.co.uk/download/sip/
DISTNAME=	sip-x11-gpl-${PORTVERSION}

MAINTAINER=	nbm@FreeBSD.org

USE_PYTHON=	yes
USE_QT_VER=	3
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=	yes

ALL_TARGET=	all install

do-configure:
	@${MKDIR} ${WRKDIR}/headers ${WRKDIR}/binaries ${WRKDIR}/modules
	@( cd ${WRKSRC} && ${PYTHON_CMD} build.py -q ${X11BASE} \
		-e ${WRKDIR}/headers -b ${WRKDIR}/binaries -d ${WRKDIR}/modules )

do-install:
	${CP} ${WRKDIR}/modules/* ${PREFIX}/lib/
	${MKDIR} ${PREFIX}/include/sip
	${CP} ${WRKDIR}/headers/* ${PREFIX}/include/sip/
	${CP} ${WRKDIR}/binaries/* ${PREFIX}/bin/

.include <bsd.port.mk>
