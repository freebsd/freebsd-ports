# New ports collection makefile for:	msql
# Version required:	1.0.14
# Date created:		14 January 1995
# Whom:			mr (original)
#
# $Id$
#

DISTNAME=	msql-1.0.16
CATEGORIES+=	databases
MASTER_SITES=	ftp://bond.edu.au/pub/Minerva/msql/

MAINTAINTER=	jfitz@freebsd.org

IS_INTERACTIVE=	yes
PREFIX=		/usr/local/Minerva
NO_MTREE=	yes
RESTRICTED=	"restrictive copyright (no commercial use)"

post-install:
.for file in Commercial License mSQL-Invoice.txt msql-pwr.README msql-pwr.gif msql-pwr2.gif
	cp ${WRKSRC}/doc/${file} ${PREFIX}/doc
.endfor
.if !defined(NOPORTDOCS)
.for file in HISTORY acl.txt mSQL-1.0.11.ps
	cp ${WRKSRC}/doc/${file} ${PREFIX}/doc
.endfor
.endif
	cp ${WRKSRC}/scripts/run_daemon ${PREFIX}

.include <bsd.port.mk>
