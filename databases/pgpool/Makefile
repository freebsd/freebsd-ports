# Created by: Choe, Cheng-Dae <whitekid@gmail.com>
# $FreeBSD$

PORTNAME=	pgpool
PORTVERSION=	3.4.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1446/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Connection pool server for PostgreSQL

USES=		gmake
GNU_CONFIGURE=	yes

USE_RC_SUBR=	pgpool
CONFLICTS=	pgpool-II-*

PORTDOCS=	README AUTHORS COPYING ChangeLog INSTALL NEWS TODO README.euc_jp

MAN8=		pgpool.8

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/$f ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
