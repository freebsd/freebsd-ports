# New ports collection makefile for:	cassandra
# Date created:		2009-08-06
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	cassandra
PORTVERSION=	0.6.3
CATEGORIES=	databases java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	cassandra/${PORTVERSION}
DISTNAME=	apache-cassandra-${PORTVERSION}
EXTRACT_SUFX=	-bin.tar.gz

MAINTAINER=	gslin@gslin.org
COMMENT=	Open source distributed database management system

JAVA_VERSION=	1.6+
NO_BUILD=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"
USE_JAVA=	yes

post-patch:
	@${MV} ${WRKSRC}/conf/log4j.properties ${WRKSRC}/conf/log4j.properties.sample
	@${MV} ${WRKSRC}/conf/storage-conf.xml ${WRKSRC}/conf/storage-conf.xml.sample

do-install:
	@${MKDIR} ${DATADIR}
	@${CP} -R ${WRKSRC}/* ${DATADIR}

.include <bsd.port.mk>
