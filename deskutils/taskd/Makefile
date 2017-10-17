# Created by: gahr
# $FreeBSD$

PORTNAME=	taskd
PORTVERSION=	1.1.0
PORTREVISION=	5
CATEGORIES=	deskutils
MASTER_SITES=	http://taskwarrior.org/download/

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Multi-user server for taskwarrior

LICENSE=	MIT

LIB_DEPENDS=	libgnutls.so:security/gnutls
RUN_DEPENDS=	bash:shells/bash

USES=		cmake:outsource compiler:c++11-lib shebangfix
USE_RC_SUBR=	taskd

USERS=		taskd
GROUPS=		taskd

TASKD_DBDIR?=	/var/db/${PORTNAME}

PLIST_SUB+=	TASKD_DBDIR="${TASKD_DBDIR}" \
		TASKD_USER="${USERS}" \
		TASKD_GROUP="${GROUPS}"

SUB_LIST+=	TASKD_DBDIR="${TASKD_DBDIR}"

SHEBANG_FILES=	demo/client/case* \
		demo/client/malformed* \
		demo/client/run \
		demo/client/setup \
		demo/server/run \
		demo/server/setup \
		mon/create \
		scripts/setup_server.bash \
		src/taskdctl \
		pki/generate \
		pki/generate.ca \
		pki/generate.client \
		pki/generate.crl \
		pki/generate.server

CFLAGS+=	-g -O0

PORTDOCS=	*

post-install:
	(cd ${WRKSRC}/pki && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})
	${MKDIR} ${STAGEDIR}${TASKD_DBDIR}

.include <bsd.port.mk>
