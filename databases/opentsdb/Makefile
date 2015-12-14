# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	opentsdb
PORTVERSION=	2.1.1
CATEGORIES=	databases java
MASTER_SITES=	https://github.com/OpenTSDB/opentsdb/releases/download/${PORTVERSION}/

MAINTAINER=	xmj@chaot.net
COMMENT=	OpenTSDB is the Scalable Timeseries Database

LICENSE=	LGPL3

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		curl:${PORTSDIR}/ftp/curl \
		gawk:${PORTSDIR}/lang/gawk
LIB_DEPENDS=	libhadoop.so:${PORTSDIR}/devel/hadoop2
RUN_DEPENDS=	hbase>0:${PORTSDIR}/databases/hbase

USES=		gmake python
USE_JAVA=	yes

OPTIONS_DEFINE=		GNUPLOT
OPTIONS_DEFAULT=	GNUPLOT

GNUPLOT_RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

HAS_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

OPENTSDB_LOGDIR=	/var/log/${PORTNAME}
OPENTSDB_RUNDIR=	/var/run/${PORTNAME}

OPENTSDB_USER=	opentsdb
OPENTSDB_GROUP=	opentsdb

USERS=		${OPENTSDB_USER}
GROUPS=		${OPENTSDB_GROUP}

USE_RC_SUBR=	opentsdb

SUB_LIST=	OPENTSDB_USER="${OPENTSDB_USER}" \
		OPENTSDB_LOGDIR="${OPENTSDB_LOGDIR}" \
		OPENTSDB_RUNDIR="${OPENTSDB_RUNDIR}"

post-patch:
	${REINPLACE_CMD} -i "" -e "s|python|${PYTHON_CMD}|" ${WRKSRC}/build-aux/gen_build_data.sh
	${REINPLACE_CMD} -i "" -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -i "" -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/src/utils/Config.java
	${REINPLACE_CMD} -i "" -e "s|tsd.http.staticroot =|tsd.http.staticroot = ${DATADIR}/static|; s|tsd.http.cachedir =|tsd.http.cachedir = /tmp/opentsdb|; s|tsd.network.port =|tsd.network.port = 4242|;" ${WRKSRC}/src/opentsdb.conf

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${OPENTSDB_LOGDIR} ${STAGEDIR}${OPENTSDB_RUNDIR}
	${INSTALL_DATA} ${WRKSRC}/src/logback.xml ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/src/opentsdb.conf ${STAGEDIR}${ETCDIR}/opentsdb.conf.sample
	(cd "${STAGEDIR}${PREFIX}"; ${FIND} -s share/${PORTNAME}/static -name \*cache.html) >> ${TMPPLIST}

.include <bsd.port.mk>
