# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pig
PORTVERSION=	0.15.0
CATEGORIES=	devel java
MASTER_SITES=	APACHE/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		LOCAL/demon/:ant \
		http://people.freebsd.org/~demon/:ant \
		http://central.maven.org/maven2/org/apache/ivy/ivy/2.2.0/:ivy
DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX} FreeBSD-${PORTNAME}-${PORTVERSION}-ant-repository.tar.gz:ant ivy-2.2.0.jar:ivy
DIST_SUBDIR=	hadoop
EXTRACT_ONLY=	${DISTNAME}-src${EXTRACT_SUFX} FreeBSD-${PORTNAME}-${PORTVERSION}-ant-repository.tar.gz

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Engine for executing data flows in parallel on Hadoop

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/ant:devel/apache-ant
RUN_DEPENDS=	bash:shells/bash \
		yarn:devel/hadoop2

BROKEN=		tries to make outbound http connection during build phase breaking tinderbox.  Software itself does not have known issues, remove this BROKEN line and build your own package

USE_JAVA=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

post-patch:
	${REINPLACE_CMD} -e "s#%%WRKDIR%%#${WRKDIR}#" ${WRKSRC}/ivy/ivysettings.xml

pre-build:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/ivy-2.2.0.jar ${WRKSRC}/ivy/

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/ant -Dhadoopversion=23

post-build:
	${REINPLACE_CMD} -e "s#%%JAVA_HOME%%#${JAVA_HOME}#" -e "s#%%LOCALBASE%%#${LOCALBASE}#" ${WRKSRC}/bin/pig

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} lib ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/pig-${PORTVERSION}-SNAPSHOT-core-h2.jar ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/pig ${STAGEDIR}/${PREFIX}/bin/

.include <bsd.port.mk>
