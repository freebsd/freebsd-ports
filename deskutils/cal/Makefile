# New ports collection makefile for:	cal
# Version required:			3.4
# Date created:				6 July 1996
# Whom: Andrey Zakhvatov <andy@cgu.chel.su>
#
# $Id$
#

DISTNAME=            cal-3.4
CATEGORIES+=         misc
MASTER_SITES=        ftp://sunsite.unc.edu/pub/Linux/utils/shell/
MAINTAINER=          andy@cgu.chel.su

WRKSRC=              ${WRKDIR}/cal34/source
ALL_TARGET=          cal

pre-patch:
	@ mv ${WRKSRC}/makefile.unx ${WRKSRC}/Makefile

do-install:
	@ install -g bin -m 0111 -o bin ${WRKSRC}/cal ${PREFIX}/bin/cal
	@ install -g bin -m 0644 -o bin ${WRKSRC}/cal.1 ${PREFIX}/man/man1/cal.1
.if !defined{NOMANCOMPRESS}
	@ gzip -9nf ${PREFIX}/man/man1/cal.1
.endif
	@ if [ ! -d ${PREFIX}/etc/cal ]; then mkdir ${PREFIX}/etc/cal; chmod 0755 ${PREFIX}/etc/cal; fi
	@ if [ ! -f ${PREFIX}/etc/cal/calcol ]; then install -g bin -m 0444 -o bin ${WRKDIR}/cal34/cal.col ${PREFIX}/etc/cal/calcol; fi
	@ if [ ! -f ${PREFIX}/etc/cal/caldat ]; then install -g bin -m 0444 -o bin ${WRKDIR}/cal34/cal.dat ${PREFIX}/etc/cal/caldat; fi

.include <bsd.port.mk>
