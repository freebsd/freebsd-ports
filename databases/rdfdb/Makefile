# New ports collection makefile for:   rdfdb
# Date created:                 28 December 2001
# Whom:                         Philip Jenvey <pjenvey@turntables.org>
#
# $FreeBSD$
#

PORTNAME=	rdfdb
PORTVERSION=	0.46
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://www.guha.com/
DISTNAME=	rdfdb_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lightweight RDF database

IGNORE=		"Uses unregistered uid that conflicts with oracle7-client"

LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3

WRKSRC=	${WRKDIR}/rdfdb
USE_GMAKE=	yes
MAKEFILE=	makefile
ALL_TARGET=
CFLAGS+=	${PTHREAD_CFLAGS}

RDFDB_DIR?=	/var/db/rdfdb
RDFDB_PORT?=	7001
PLIST_SUB=	RDFDB_DIR=${RDFDB_DIR}

post-patch:
	@${SED} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		-e 's,%%PTHREAD_LIBS%%,${PTHREAD_LIBS:S/"//g},g' \
		< ${WRKSRC}/makefile > ${WRKSRC}/makefile.new
	@${MV} ${WRKSRC}/makefile.new ${WRKSRC}/makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/rdfdb ${PREFIX}/bin
.if !exists(${RDFDB_DIR})
	@${MKDIR} ${RDFDB_DIR}
.endif
	@${SETENV} RDFDB_DIR=${RDFDB_DIR} ${SH} ${PKGINSTALL} ${PKGNAME} \
		PRE-INSTALL
	@${SED} "s|%%PREFIX%%|${PREFIX}|g; s|%%RDFDB_DIR%%|${RDFDB_DIR}|g; \
		s|%%RDFDB_PORT%%|${RDFDB_PORT}|g" \
		< ${FILESDIR}/rdfdb-server.sh.tmpl \
		> ${PREFIX}/etc/rc.d/rdfdb-server.sh
	@${CHMOD} 554 ${PREFIX}/etc/rc.d/rdfdb-server.sh
	@${CHOWN} root:rdfdb ${PREFIX}/etc/rc.d/rdfdb-server.sh

.include <bsd.port.mk>
