# New ports collection makefile for:	pgpool
# Date created:				2005-10-19
# Whom:					Choe, Cheng-Dae <whitekid@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pgpool-II
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1258/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	A connection pool server for PostgreSQL

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PGSQL=	yes

CONFLICTS=	pgpool-3.*
CONFIGURE_ARGS=	--datadir=${DATADIR}
USE_RC_SUBR=	pgpool

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README README.euc_jp
PORTDOCS+=	TODO
PORTDOCShtml=	pgpool-en.html pgpool-ja.html pgpool.css
PORTDOCShtml+=	tutorial-en.html tutorial-ja.html

MAN8=		pgpool.8

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/$f ${DOCSDIR}
.endfor
.for f in ${PORTDOCShtml}
	${INSTALL_MAN} ${WRKSRC}/doc/$f ${DOCSDIR}
.endfor
PORTDOCS+=	${PORTDOCShtml}
.endif

.include <bsd.port.mk>
