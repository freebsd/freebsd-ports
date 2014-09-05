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

USES+=		bison gmake pgsql

PORTSCOUT=	site:http://pgfoundry.org/frs/?group_id=1000207

.include <bsd.port.pre.mk>

.if ${PGSQL_VER} > 9.1
PLIST_SUB+=	NEW_CONTRIB_DIR=""  OLD_CONTRIB_DIR="@comment "
.else
PLIST_SUB+=	NEW_CONTRIB_DIR="@comment "  OLD_CONTRIB_DIR=""
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^#ifdef/s| SYS_| HAVE_SYS_|' ${WRKSRC}/src/execute.c

.include <bsd.port.post.mk>
