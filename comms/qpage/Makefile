# New ports collection makefile for:	qpage
# Version required:	3.2
# Date created:		02 Aug 1997
# Whom:			joes@seaport.net
#
# $Id: Makefile,v 1.2 1998/06/03 06:13:48 vanilla Exp $
#

DISTNAME=	qpage-3.2
CATEGORIES=	comms
MASTER_SITES=	http://www.qpage.org/download/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	joes@seaport.net

MAN1=		qpage.1

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/qpage.sh ]; then \
		${ECHO} "Install ${PREFIX}/etc/rc.d/qpage.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/qpage.sh; \
		${ECHO} "[ -x ${PREFIX}/bin/qpage ] && ${PREFIX}/bin/qpage -q10 && echo -n ' qpage'" >> ${PREFIX}/etc/rc.d/qpage.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/qpage.sh; \
	fi

.include <bsd.port.mk>
