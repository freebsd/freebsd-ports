# New ports collection makefile for:	IrcII Client
# Version required:	2.6
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $Id:$
#

DISTNAME=	ircII2.6
GNU_CONFIGURE=	YES
MASTER_SITES=	ftp://cs-ftp.bu.edu/irc/clients/
EXTRACT_SUFX=	.tar.Z
WRKSRC=		${WRKDIR}/ircii-2.6

pre-install:
	mkdir -p ${PREFIX}/bin
	mkdir -p ${PREFIX}/lib/irc/script
	mkdir -p ${PREFIX}/lib/irc/translation
	@if [ ! -f ${DISTDIR}/${DISTNAME}help${EXTRACT_SUFX} ]; then \
	   echo ">> Sorry, can't find: ${DISTDIR}/${DISTNAME}help${EXTRACT_SUFX}"; \
	   echo ">> Please obtain this file from:"; \
	   echo ">>     $(HOME_LOCATION)"; \
	   echo ">> if you want local helpfiles."; \
	   exit 1; \
        fi
	@tar xzf ${DISTDIR}/${DISTNAME}help${EXTRACT_SUFX} -C ${PREFIX}/lib/irc; \

.include <bsd.port.mk>
