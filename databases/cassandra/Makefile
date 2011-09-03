# New ports collection makefile for:	cassandra
# Date created:		2009-08-06
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	cassandra
PORTVERSION=	0.8.4
CATEGORIES=	databases java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	cassandra/${PORTVERSION}
DISTNAME=	apache-cassandra-${PORTVERSION}
EXTRACT_SUFX=	-bin.tar.gz

MAINTAINER=	gslin@gslin.org
COMMENT=	Open source distributed database management system

LICENSE=	ASL

JAVA_VERSION=	1.6+
USE_JAVA=	yes
USE_RC_SUBR=	cassandra

CONFIGS=	cassandra.yaml log4j-server.properties access.properties \
		log4j-tools.properties passwd.properties \
		cassandra-topology.properties

do-build:
.for i in ${CONFIGS}
	@${MV} ${WRKSRC}/conf/${i} ${WRKSRC}/conf/${i}.sample
.endfor

do-install:
	@${MKDIR} ${DATADIR}
	@${CP} -R ${WRKSRC}/* ${DATADIR}
	@${RM} ${DATADIR}/bin/*.bat

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
