# New ports collection makefile for:	aolserver-nspostgres
# Date created:		12 Oct 2006
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nspostgres
PORTVERSION=	4.1
PORTREVISION=	3
DISTVERSIONSUFFIX=	-src
CATEGORIES=	databases www
MASTER_SITES=	SF/aolserver/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	aolserver-
DIST_SUBDIR=	aolserver

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Internal PostgreSQL driver for AOLserver

LICENSE=	MPL

WRKSRC=		${WRKDIR}/nspostgres-${PORTVERSION}

AOLSERVERBASE?=	aolserver
BUILD_DEPENDS+=	${LOCALBASE}/${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver
RUN_DEPENDS+=	${LOCALBASE}/${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver

USE_PGSQL=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAKE_ARGS=	AOLSERVER="${LOCALBASE}/${AOLSERVERBASE}" \
		PG_CONFIG="${LOCALBASE}/bin/pg_config" \
		POSTGRES=PG_CONFIG ACS=1 OPENSSL=1

PLIST_FILES=	${AOLSERVERBASE}/bin/nspostgres.so \
		${AOLSERVERBASE}/lib/libnspostgres.a \
		${AOLSERVERBASE}/lib/libnspostgres.so

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog README
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e '/^MODOBJS   =.*/{n;s/.*/OBJS  = $$(MODOBJS)/g;G;}' \
		-e '/MODLIBS *+=.*/{p;s/MODLIBS *+=/DLLLIBS  +=/g;}' \
		${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@ ${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
