# New ports collection makefile for:	drexelsnmp
# Date created:				2005-02-15
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	drexelsnmp
PORTVERSION=	1.4
CATEGORIES=	java devel net-mgmt
MASTER_SITES=	http://edge.mcs.drexel.edu/GICL/people/sevy/snmp/
DISTNAME=	source_${PORTVERSION}

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Java SNMP protocol implementation

USE_JAVA=	yes
USE_ZIP=	yes

CLASSDIR=	${PREFIX}/share/java/classes
NO_WRKSUBDIR=	yes

do-build:
	${MKDIR} ${WRKSRC}/build_library
	(cd ${WRKSRC} && ${JAVAC} -sourcepath source -d build_library source/snmp/*.java && ${JAR} cvf snmp.jar -C build_library/ .)

do-install:
	${INSTALL} -d -o root -g wheel -m 0755 ${CLASSDIR}
	${INSTALL_DATA} ${WRKSRC}/snmp.jar ${CLASSDIR}/

.include <bsd.port.mk>
