# New ports collection makefile for:	ipcheck
# Date created:		24 Mar 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ipcheck
PORTVERSION=	0.195
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://ipcheck.sourceforge.net/%SUBDIR%/
MASTER_SITE_SUBDIR=	. release
DISTNAME=	ipcheck.py
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	lioux@FreeBSD.org

USE_PYTHON=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

.ifdef(WITH_SNMP)
RUN_DEPENDS+=	${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/pysnmp/v2c.py:${PORTSDIR}/net/py-snmp
.endif

pre-everything::
.ifndef(WITH_SNMP)
	@${ECHO_MSG} '===> Enable SNMP support by defining WITH_SNMP'
.endif

do-patch:
	@${SED} -e "s!/usr/bin/python!${LOCALBASE}/bin/python!" \
		-e "s!ppp0!tun0!" \
			${DISTDIR}/${DISTNAME} > ${WRKDIR}/${DISTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}.py

.include <bsd.port.mk>
