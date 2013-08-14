# Created by: verm@drunkmonk.net
# $FreeBSD$

PORTNAME=	fastresolve
PORTVERSION=	2.10
PORTREVISION=	4
CATEGORIES=	dns
MASTER_SITES=	http://www.djmnet.org/sw/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programs that process web logs to get DNS and domain ownership info

LIB_DEPENDS=	adns.1:${PORTSDIR}/dns/adns
RUN_DEPENDS=	p5-BerkeleyDB>=0:${PORTSDIR}/databases/p5-BerkeleyDB

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL=${PERL}
LDFLAGS+=	-L${LOCALBASE}/lib
CXXFLAGS+=	-I${LOCALBASE}/include
USE_AUTOTOOLS=	aclocal14 automake14 autoconf213

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
