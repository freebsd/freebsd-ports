# New ports collection makefile for:	migrate
# Date created:		6 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	migrate
PORTVERSION=	1.2.4
CATEGORIES=	biology
MASTER_SITES=	ftp://evolution.genetics.washington.edu/pub/lamarc/migrate/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	wjv@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFIGURE_WRKSRC=	${WRKSRC}/src
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}
GNU_CONFIGURE=	yes

MAN1=		migrate.1

post-install:
	@ cd ${PREFIX}/bin && ${LN} -s migrate-n migrate
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}/graphics
.for docfile in HISTORY HOWTO-PARALLEL README migrate.html
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
	@ ${INSTALL_DATA} ${WRKSRC}/graphics/* ${DOCSDIR}/graphics
.endif

.include <bsd.port.mk>
