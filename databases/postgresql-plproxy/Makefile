# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	plproxy
PORTVERSION=	2.5
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/3392/
PKGNAMEPREFIX=	postgresql-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PL/Proxy - database partitioning system

LICENSE=	BSD

USES=		bison gmake
USE_PGSQL=	yes
MAKE_JOBS_SAFE=	yes

PORTSCOUT=	site:http://pgfoundry.org/frs/?group_id=1000207

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/postmaster)
PGSQL_VER!=	${LOCALBASE}/bin/postmaster -V | \
		${SED} -En 's/.*PostgreSQL[^0-9]*([0-9]+)\.([0-9]+)\..*/\1\2/p'
.elif exists(${LOCALBASE}/bin/pg_config)
PGSQL_VER!=	${LOCALBASE}/bin/pg_config --version | \
		${SED} -n 's/PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)[^0-9].*/\1\2/p'
.else
PGSQL_VER=	${DEFAULT_PGSQL_VER}
.endif

.if ${PGSQL_VER} > 91
PLIST_SUB+=	NEW_CONTRIB_DIR=""  OLD_CONTRIB_DIR="@comment "
.else
PLIST_SUB+=	NEW_CONTRIB_DIR="@comment "  OLD_CONTRIB_DIR=""
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^#ifdef/s| SYS_| HAVE_SYS_|' ${WRKSRC}/src/execute.c

.include <bsd.port.post.mk>
