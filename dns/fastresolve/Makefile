# New ports collection makefile for:	fastresolve
# Date created:		11 June 2002
# Whom:			verm@drunkmonk.net
#
# $FreeBSD$
#

PORTNAME=	fastresolve
PORTVERSION=	2.10
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	http://www.djmnet.org/sw/dist/

MAINTAINER=	martin@tradex.sk
COMMENT=	Programs that process web logs to get DNS and domain ownership info

LIB_DEPENDS=	adns.1:${PORTSDIR}/dns/adns
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB

USE_BZIP2=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CXXFLAGS="-I${LOCALBASE}/include" \
		PERL=${PERL}
USE_AUTOMAKE_VER=	14
USE_AUTOCONF_VER=	213

# Default to db3
WITH_BDB_VER?=	3

.if ${WITH_BDB_VER} == 3
LIB_DEPENDS+=	db3.3:${PORTSDIR}/databases/db3
CONFIGURE_ARGS=	--with-bdb-lib=-ldb3_cxx --with-bdb-incdir=${LOCALBASE}/include/db3
.elif ${WITH_BDB_VER} == 4
LIB_DEPENDS+=	db4.0:${PORTSDIR}/databases/db4
CONFIGURE_ARGS=	--with-bdb-lib=-ldb4_cxx --with-bdb-incdir=${LOCALBASE}/include/db4
.elif ${WITH_BDB_VER} == 41
LIB_DEPENDS+=	db41.1:${PORTSDIR}/databases/db41
CONFIGURE_ARGS=	--with-bdb-lib=-ldb41_cxx --with-bdb-incdir=${LOCALBASE}/include/db41
.elif ${WITH_BDB_VER} == 42
LIB_DEPENDS+=	db-4.2:${PORTSDIR}/databases/db42
CONFIGURE_ARGS=	--with-bdb-lib=-ldb_cxx-4.2 --with-bdb-incdir=${LOCALBASE}/include/db42
.else
.error WITH_BDB_VER must be one between 3, 4, 41 or 42
.endif

MAN1=	dns-terror.1 btree-dump.1 convert-dom-db.1 convert-ip-db.1 \
	expire-ip-db.1 getdominfo.1 rebuild-dom-db.1 rebuild-ip-db.1 \
	reresolve.1 make-report.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog INSTALL NEWS README
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/doc/TODO ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/timings ${DOCSDIR}
.endif

.include <bsd.port.mk>
