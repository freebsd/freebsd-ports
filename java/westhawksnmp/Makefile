# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	westhawksnmp
PORTVERSION=	5.1
PORTREVISION=	2
CATEGORIES=	java net-mgmt devel
MASTER_SITES=	http://snmp.westhawk.co.uk/
DISTNAME=	${PORTNAME:S/westhawk//}${PORTVERSION:S/./_/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight SNMP stack for Java

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2012-11-26

USE_JAVA=	yes
USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/snmp5_1.jar ${JAVAJARDIR}/snmp.jar
	${INSTALL_DATA} ${WRKSRC}/lib/snmpOracle5_1.jar ${JAVAJARDIR}/snmpOracle.jar
	${INSTALL_DATA} ${WRKSRC}/lib/tablelayout.jar ${JAVAJARDIR}/
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc ${DOCSDIR}/
.endif

.include <bsd.port.mk>
