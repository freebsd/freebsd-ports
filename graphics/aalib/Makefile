# New ports collection makefile for:	aalib
# Version required:			1.2
# Date created:				9 Dec 1997
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.2 1998/03/28 14:33:26 steve Exp $
#

DISTNAME=		aalib-1.2
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.ta.jcu.cz/pub/aa/

MAINTAINER=		andy@icc.surw.chel.su

BROKEN=			build

GNU_CONFIGURE=		yes

pre-configure:
	@${RM} ${WRKSRC}/config.cache

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi

.include <bsd.port.mk>
