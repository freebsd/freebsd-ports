# Created by: Philip Jenvey <pjenvey@turntables.org>
# $FreeBSD$

PORTNAME=	rdfdb
PORTVERSION=	0.46
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://www.guha.com/
DISTNAME=	rdfdb_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight RDF database

USE_BDB=	40+
INVALID_BDB_VER=2

USERS=	rdfdb
GROUPS=	rdfdb

WRKSRC=	${WRKDIR}/rdfdb
USE_GMAKE=	yes
MAKEFILE=	makefile
ALL_TARGET=
CFLAGS+=	${PTHREAD_CFLAGS} -Wno-return-type

RDFDB_PORT?=	7001

PLIST_FILES=	bin/rdfdb bin/rdfdb etc/rc.d/rdfdb-server.sh

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		-e 's,%%PTHREAD_LIBS%%,${PTHREAD_LIBS:S/"//g},g' \
		-e 's,%%BDB_INCLUDE_DIR%%,${BDB_INCLUDE_DIR},g'\
		-e 's,%%BDB_LIB_NAME%%,${BDB_LIB_NAME},g' \
		${WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rdfdb ${PREFIX}/bin
	@${SED} "s|%%PREFIX%%|${PREFIX}|g; s|%%RDFDB_DIR%%|${RDFDB_DIR}|g; \
		s|%%RDFDB_PORT%%|${RDFDB_PORT}|g" \
		< ${FILESDIR}/rdfdb-server.sh.tmpl \
		> ${PREFIX}/etc/rc.d/rdfdb-server.sh
	@${CHMOD} 554 ${PREFIX}/etc/rc.d/rdfdb-server.sh
	@${CHOWN} root:rdfdb ${PREFIX}/etc/rc.d/rdfdb-server.sh

.include <bsd.port.mk>
