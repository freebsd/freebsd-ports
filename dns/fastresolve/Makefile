# New ports collection makefile for:	fastresolve
# Date created:		11 June 2002
# Whom:			verm@drunkmonk.net
#
# $FreeBSD$
#

PORTNAME=	fastresolve
PORTVERSION=	2.10
CATEGORIES=	sysutils
MASTER_SITES=	http://www.djmnet.org/sw/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programs that process web logs to get DNS and domain ownership info

LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3 \
		adns.1:${PORTSDIR}/net/adns

USE_BZIP2=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CXXFLAGS="-I${LOCALBASE}/include/db3 -I${LOCALBASE}/include"

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

	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you want to use the convert-ip-db script you must"
	@${ECHO_MSG} "install the databases/p5-BerkeleyDB port"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
