# New ports collection makefile for:	msql
# Version required:	1.0.14
# Date created:		14 January 1995
# Whom:			mr (original)
#
# $Id: Makefile,v 1.9 1995/09/14 11:27:52 asami Exp $
#

DISTNAME=	msql-1.0.14
CATEGORIES+=	databases
MASTER_SITES=	ftp://bond.edu.au/pub/Minerva/msql/

IS_INTERACTIVE=	yes
PREFIX=		/usr/local/Minerva
NO_MTREE=	yes
RESTRICTED=	"restrictive copyright (no commercial use)"

post-install:
.for file in License Rates.txt mSQL-Invoice.txt
	cp ${WRKSRC}/doc/${file} ${PREFIX}/doc
.endfor
.if !defined(NOPORTDOCS)
.for file in HISTORY acl.txt mSQL-1.0.11.ps
	cp ${WRKSRC}/doc/${file} ${PREFIX}/doc
.endfor
.endif

.include <bsd.port.mk>
