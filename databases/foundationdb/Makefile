# Created by: vanilla@
# $FreeBSD$

PORTNAME=	foundationdb
PORTVERSION=	5.2.8
PORTREVISION=	2
CATEGORIES=	databases

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Distributed, transactional key-value store

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	not yet ported to anything other than amd64

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libeio.so:devel/libeio

USES=		compiler:c++14-lang gmake mono python:build shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	apple
USE_RC_SUBR=	foundationdb
SHEBANG_FILES=	build/csprojtom4.py build/link-wrapper.sh build/vcxprojtom4.py \
		bindings/c/generate_asm.py
MAKE_ENV+=	PYTHON=${PYTHON_CMD}
CXXFLAGS+=	-Wno-varargs

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}
DBDIR?=		/var/db/foundationdb
LOGDIR?=	/var/log/foundationdb

PLIST_SUB+=	DB_USER=${USERS} \
		DB_GROUP=${GROUPS} \
		DB_DIR=${DBDIR} \
		LOG_DIR=${LOGDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/foundationdb.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/fdbbackup ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/fdbcli ${STAGEDIR}${PREFIX}/bin
	${LN} -sf ${PREFIX}/bin/fdbbackup ${STAGEDIR}${PREFIX}/bin/fdbrestore
	${INSTALL_PROGRAM} ${WRKSRC}/bin/fdbmonitor ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/fdbserver ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/foundationdb
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/foundationdb/backup_agent
	${LN} -sf ${PREFIX}/bin/fdbbackup ${STAGEDIR}${PREFIX}/lib/foundationdb/backup_agent/backup_agent
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/foundationdb
	${INSTALL_DATA} ${WRKSRC}/foundationdb.conf ${STAGEDIR}${PREFIX}/etc/foundationdb/foundationdb.conf.sample
	@${MKDIR} ${STAGEDIR}${DBDIR}
	@${MKDIR} ${STAGEDIR}${LOGDIR}

.include <bsd.port.mk>
