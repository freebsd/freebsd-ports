# New ports collection makefile for:	aalib
# Version required:			1.2
# Date created:				9 Dec 1997
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1997/12/19 08:59:36 vanilla Exp $
#

DISTNAME=		aalib-1.2
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.ta.jcu.cz/pub/aa/

MAINTAINER=		andy@icc.surw.chel.su

GNU_CONFIGURE=		yes

pre-configure:
	@${RM} ${WRKSRC}/config.cache

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi

.include <bsd.port.mk>
