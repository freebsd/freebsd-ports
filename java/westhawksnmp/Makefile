# New ports collection makefile for:	westhawksnmp
# Date created:				2004-10-25
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	westhawksnmp
PORTVERSION=	4.13
CATEGORIES=	java devel net-mgmt
MASTER_SITES=	http://snmp.westhawk.co.uk/
DISTNAME=	${PORTNAME:S/westhawk//}${PORTVERSION:S/./_/}

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Lightweight SNMP stack for Java

NO_BUILD=	yes
USE_JAVA=	yes
USE_ZIP=	yes
NO_BUILD=	yes

CLASSDIR=	${PREFIX}/share/java/classes
NO_WRKSUBDIR=	yes

do-install:
	${INSTALL} -d -o root -g wheel -m 0755 ${CLASSDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/snmp4_13.jar ${CLASSDIR}/snmp.jar
	${INSTALL_DATA} ${WRKSRC}/snmpOracle4_13.jar ${CLASSDIR}/snmpOracle.jar
	${INSTALL_DATA} ${WRKSRC}/tablelayout.jar ${CLASSDIR}/
	${CP} -R ${WRKSRC}/org ${WRKSRC}/stubs ${DATADIR}/
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${WRKSRC}/*.txt ${DOCSDIR}/
	${CP} -R ${WRKSRC}/javadoc ${WRKSRC}/uk ${DOCSDIR}/
.endif

.include <bsd.port.mk>
