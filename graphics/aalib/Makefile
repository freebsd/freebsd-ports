# New ports collection makefile for:	aalib
# Version required:			1.1.6
# Date created:				9 Dec 1997
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=		aalib-1.1.6
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.ta.jcu.cz/pub/aa/development/

MAINTAINER=		andy@icc.surw.chel.su

WRKSRC=			${WRKDIR}/aalib-1.1
GNU_CONFIGURE=		yes

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi

.include <bsd.port.mk>
