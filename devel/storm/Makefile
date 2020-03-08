# Created by: Radim Kolar <hsn@sendmail.cz>
# $FreeBSD$

PORTNAME=	storm
DISTVERSION=	0.9.2-incubating
CATEGORIES=	devel java
MASTER_SITES=	APACHE/incubator/${PORTNAME}/apache-${PORTNAME}-${DISTVERSION}
DISTNAME=	apache-storm-${DISTVERSION}

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Distributed realtime computation system

LICENSE=	APACHE20

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

USES=		python:2.7
USE_JAVA=	yes
JAVA_VERSION=	1.7
JAVA_VENDOR=	openjdk
NO_ARCH=	yes
USE_RC_SUBR=	storm-nimbus storm-supervisor

NO_BUILD=	yes

STORM_DIRS=	bin examples external lib public
STORM_CFG_DIRS=	conf logback
STORM_CFG_FILES=	conf/storm.yaml conf/storm_env.ini logback/cluster.xml

post-extract:
		${RM} ${WRKSRC}/bin/*.cmd

post-patch:
		${REINPLACE_CMD} -e "s|/usr/bin/python|${LOCALBASE}/bin/python2.7|" ${WRKSRC}/bin/storm
		${RM} ${WRKSRC}/bin/*.bak
.for i in ${STORM_CFG_FILES}
		${MV} ${WRKSRC}/${i} ${WRKSRC}/${i}.sample
.endfor

do-install:
		${MKDIR} ${STAGEDIR}${DATADIR}
		cd ${WRKSRC} && ${FIND} ${STORM_DIRS} ${STORM_CFG_DIRS} | \
			${CPIO} --quiet -pdmu ${STAGEDIR}${DATADIR}
		${INSTALL_DATA} ${WRKSRC}/RELEASE ${STAGEDIR}${DATADIR}
		${LN} -sf ${DATADIR}/bin/storm ${STAGEDIR}${PREFIX}/bin/storm

.include <bsd.port.mk>
