# New ports collection makefile for:	ipcheck
# Date created:		24 Mar 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ipcheck
PORTVERSION=	0.226
PORTEPOCH=	1
CATEGORIES=	dns python
MASTER_SITES=	http://ipcheck.sourceforge.net/releases/
MASTER_SITE_SUBDIR=	lioux
DISTNAME=	${PORTNAME}.${PORTVERSION:S/^0.//}
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A fully compliant DynDNS.org client for UNIX (supports NIC v2.0)

USE_PYTHON=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/ipcheck.py

.ifdef(WITH_SNMP)
RUN_DEPENDS+=	${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages/pysnmp/v2c.py:${PORTSDIR}/net-mgmt/py-snmp
.endif

pre-everything::
.ifndef(WITH_SNMP)
	@${ECHO_MSG} '===> Enable SNMP support by defining WITH_SNMP'
.endif

do-patch:
	@${SED} \
		-e "s!/usr/bin/python!${LOCALBASE}/bin/python!" \
		-e "s!ppp0!tun0!" \
		${DISTDIR}/${DISTNAME} > ${WRKDIR}/${DISTNAME}
do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME} ${PREFIX}/bin/${PORTNAME}.py

.include <bsd.port.mk>
