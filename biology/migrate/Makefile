# New ports collection makefile for:	migrate
# Date created:		6 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	migrate
PORTVERSION=	2.0.3
CATEGORIES=	biology
MASTER_SITES=	ftp://evolution.genetics.washington.edu/pub/lamarc/migrate/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to estimate population sizes and migration rates

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		migrate.1
MLINKS=		migrate.1 migrate-n.1

DOCS=		HISTORY HOWTO-PARALLEL README migrate.html
EXAMPLES=	README infile.benchmark infile.ep infile.msat infile.seq \
		parmfile parmfile.benchmark parmfile.ep parmfile.msat \
		parmfile.seq

post-patch:
		@${REINPLACE_CMD} 's,-falign-loops=16,,g' ${WRKSRC}/configure

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/migrate-n ${PREFIX}/bin
	@ cd ${PREFIX}/bin && ${LN} -s migrate-n migrate
	@ ${INSTALL_MAN} ${WRKSRC}/migrate.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}/graphics
.for file in ${DOCS}
	@ ${INSTALL_DATA} ${WRKSRC}/../${file} ${DOCSDIR}
.endfor
	@ ${MKDIR} ${EXAMPLESDIR}
.for file in ${EXAMPLES}
	@ ${INSTALL_DATA} ${WRKSRC}/../example/${file} ${EXAMPLESDIR}
.endfor
	@ ${INSTALL_DATA} ${WRKSRC}/../graphics/* ${DOCSDIR}/graphics
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
