# New ports collection makefile for:	pgpool
# Date created:				2005-10-19
# Whom:					Choe, Cheng-Dae <whitekid@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pgpool
PORTVERSION=	3.0.1
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/733/

MAINTAINER=	whitekid@gmail.com
COMMENT=	A connection pool server for PostgreSQL

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

USE_RC_SUBR=	pgpool

PORTDOCS=	README AUTHORS COPYING ChangeLog INSTALL NEWS TODO README.euc_jp

MAN8=		pgpool.8

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/$f ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
