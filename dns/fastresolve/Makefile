# New ports collection makefile for:	fastresolve
# Date created:		11 June 2002
# Whom:			verm@drunkmonk.net
#
# $FreeBSD$
#

PORTNAME=	fastresolve
PORTVERSION=	2.10
PORTREVISION=	4
CATEGORIES=	dns
MASTER_SITES=	http://www.djmnet.org/sw/dist/

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Programs that process web logs to get DNS and domain ownership info

LIB_DEPENDS=	adns.1:${PORTSDIR}/dns/adns
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB

USE_BZIP2=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CXXFLAGS="-I${LOCALBASE}/include" \
		PERL=${PERL}
USE_AUTOTOOLS=	automake:14 autoconf:213

USE_BDB=	yes
CONFIGURE_ARGS=	--with-bdb-lib=-l${BDB_LIB_CXX_NAME} --with-bdb-incdir=${BDB_INCLUDE_DIR}

MAN1=	dns-terror.1 btree-dump.1 convert-dom-db.1 convert-ip-db.1 \
	expire-ip-db.1 getdominfo.1 rebuild-dom-db.1 rebuild-ip-db.1 \
	reresolve.1 make-report.1

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog INSTALL NEWS README
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
	@${INSTALL_DATA} ${WRKSRC}/doc/TODO ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/timings ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
