# New ports collection makefile for:	cftp
# Version required:			0.9.1
# Date created:				14 October 1997
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=	cftp-0.9.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.giga.or.at/pub/nih/cftp/

MAINTAINER=	andy@icc.surw.chel.su

GNU_CONFIGURE=	yes

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	    ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi

post-install:
	@ ${MKDIR} ${PREFIX}/share/doc/cftp
.for file in AUTHORS ChangeLog NEWS README THANKS TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/cftp
.endfor

.include <bsd.port.mk>
