# New ports collection makefile for:	cassandra
# Date created:		2009-08-06
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	cassandra
PORTVERSION=	0.4.2
CATEGORIES=	databases java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	incubator/cassandra/${PORTVERSION}
DISTNAME=	apache-cassandra-incubating-${PORTVERSION}
EXTRACT_SUFX=	-bin.tar.gz

MAINTAINER=	gslin@gslin.org
COMMENT=	Open source distributed database management system

JAVA_VERSION=	1.6+
NO_BUILD=	yes
USE_JAVA=	yes

post-patch:
	${MV} ${WRKSRC}/conf/log4j.properties ${WRKSRC}/conf/log4j.properties.sample
	${MV} ${WRKSRC}/conf/storage-conf.xml ${WRKSRC}/conf/storage-conf.xml.sample

do-install:
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/* ${DATADIR}

.include <bsd.port.mk>
