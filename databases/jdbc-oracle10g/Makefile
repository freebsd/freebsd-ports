# Created by: José García Juanino <jjuanino@gmail.com>
# $FreeBSD$

PORTNAME=	oracle10g
PORTVERSION=	10.2.0.5
PORTREVISION=	1
CATEGORIES=	databases java
MASTER_SITES=	# http://www.oracle.com/technetwork/database/enterprise-edition/jdbc-10201-088211.html
PKGNAMEPREFIX=	jdbc-
DISTNAME=	ojdbc14.jar
EXTRACT_SUFX=	# none
DIST_SUBDIR=	oracle10g

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The JDBC drivers for Oracle 10g

USE_JAVA=	yes
JAVA_VERSION=	1.6+

NO_BUILD=	yes

RESTRICTED=	Packaging prohibited by Oracle license
NO_CDROM=	Packaging prohibited by Oracle license

NO_WRKSUBDIR=	yes

PLIST_FILES=	%%JAVAJARDIR%%/ojdbc-${PORTVERSION}.jar

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTFILES})
IGNORE=	due to Oracle license restrictions, you must fetch the source\
distribution manually. Please access\
http://www.oracle.com/technetwork/database/enterprise-edition/jdbc-10201-088211.html\
(Oracle Database 10g Release 2 (${PORTVERSION} JDBC Drivers) with a web\
browser and follow the link for the ${DISTFILES}. You will be required to\
register and log in, but you can create an account on that page. After\
registration and accepting the Oracle License, download the distribution\
file, ${DISTFILES}, place into ${DISTDIR}/${DIST_SUBDIR}, and restart this\
installation
.endif

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${STAGEDIR}${JAVAJARDIR}/ojdbc-${PORTVERSION}.jar

.include <bsd.port.post.mk>
