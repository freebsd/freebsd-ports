# New ports collection makefile for:	msql
# Version required:	1.0.16
# Date created:		14 January 1995
# Whom:			mr (original)
#
# $Id: Makefile,v 1.13 1996/10/04 00:38:34 jfitz Exp $
#

DISTNAME=	msql-1.0.16
CATEGORIES=	databases
MASTER_SITES=	ftp://bond.edu.au/pub/Minerva/msql/

MAINTAINTER=	jfitz@FreeBSD.ORG

#IS_INTERACTIVE=	yes
RESTRICTED=	"restrictive copyright (no commercial use)"
NO_MTREE=	yes

post-install:
.for file in Commercial License mSQL-Invoice.txt msql-pwr.README msql-pwr.gif msql-pwr2.gif
		${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/Minerva/doc
.endfor
.if !defined(NOPORTDOCS)
.for file in HISTORY acl.txt mSQL-1.0.11.ps
		${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/Minerva/doc
.endfor
.endif
		${INSTALL_SCRIPT} ${WRKSRC}/scripts/run_daemon ${PREFIX}/Minerva
		@ ${MKDIR} ${PREFIX}/etc/rc.d
		@ if [ ! -f ${PREFIX}/etc/rc.d/msql.sh ]; then \
			echo "Installing ${PREFIX}/etc/rc.d/msql.sh startup file."; \
			echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/msql.sh; \
			echo "[ -x ${PREFIX}/Minerva/bin/msqld ] && ${PREFIX}/Minerva/bin/msqld & && echo -n ' msql'" >> ${PREFIX}/etc/rc.d/msql.sh; \
			chmod 751 ${PREFIX}/etc/rc.d/msql.sh; \
		fi

.include <bsd.port.mk>
