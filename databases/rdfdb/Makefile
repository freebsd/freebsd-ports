# Created by: Philip Jenvey <pjenvey@turntables.org>
# $FreeBSD$

PORTNAME=	rdfdb
PORTVERSION=	0.46
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://www.guha.com/
DISTNAME=	rdfdb_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight RDF database

USE_BDB=	40+
INVALID_BDB_VER=2

USERS=	rdfdb
GROUPS=	rdfdb

WRKSRC=		${WRKDIR}/rdfdb
USES=		gmake
MAKEFILE=	makefile
ALL_TARGET=
CFLAGS+=	${PTHREAD_CFLAGS} -Wno-return-type
SUB_LIST+=	RDFDB_PORT="${RDFDB_PORT}" RDFDB_DIR="${RDFDB_DIR}"
USE_RC_SUBR=	rdfdb-server

RDFDB_PORT?=	7001

PLIST_FILES=	bin/rdfdb

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		-e 's,%%PTHREAD_LIBS%%,${PTHREAD_LIBS:S/"//g},g' \
		-e 's,%%BDB_INCLUDE_DIR%%,${BDB_INCLUDE_DIR},g'\
		-e 's,%%BDB_LIB_NAME%%,${BDB_LIB_NAME},g' \
		${WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rdfdb ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
