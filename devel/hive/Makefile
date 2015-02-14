# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hive
PORTVERSION=	1.0.0
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE} \
		LOCAL/demon/:maven \
		http://people.freebsd.org/~demon/:maven
MASTER_SITE_SUBDIR=${PORTNAME}/stable
DISTFILES=	apache-${PORTNAME}-${PORTVERSION}-src${EXTRACT_SUFX} FreeBSD-${PORTNAME}-${PORTVERSION}-maven-repository.tar.gz:maven
DIST_SUBDIR=	hadoop

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Framework for data warehousing on top of Hadoop

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/share/java/maven3/bin/mvn:${PORTSDIR}/devel/maven3 \
		bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		yarn:${PORTSDIR}/devel/hadoop2

USE_JAVA=	yes
JAVA_VERSION=	1.7+
WRKSRC=		${WRKDIR}/apache-${PORTNAME}-${PORTVERSION}-src

HIVE_DIST=	${WRKSRC}/packaging/target/apache-hive-${PORTVERSION}-bin/apache-hive-${PORTVERSION}-bin

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/share/java/maven3/bin/mvn -Dmaven.repo.local=${WRKDIR}/m2 --offline clean install -Phadoop-2,dist -DskipTests

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${HIVE_DIST} && ${COPYTREE_BIN} bin ${STAGEDIR}${DATADIR}
	cd ${HIVE_DIST} && ${COPYTREE_SHARE} "conf examples hcatalog lib scripts" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
