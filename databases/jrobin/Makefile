# ex:ts=8
# Ports collection makefile for:	JRobin
# Date created:			Mar 9, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jrobin
PORTVERSION=	1.5.9
CATEGORIES=	databases java
MASTER_SITES=	http://repo.opennms.org/maven2/org/${PORTNAME}/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A pure Java alternative to RRDTool

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes

CLASSES=	jrobin

do-install:
.for c in ${CLASSES}
	${INSTALL_DATA} ${DISTDIR}/${c}-${PORTVERSION}.jar ${JAVAJARDIR}/${c}.jar
	@${ECHO} '${JAVAJARDIR:S,^${PREFIX}/,,}/${c}.jar' >> ${TMPPLIST}
.endfor

.include <bsd.port.mk>
