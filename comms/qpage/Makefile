# New ports collection makefile for:	qpage
# Date created:		02 Aug 1997
# Whom:			joes@seaport.net
#
# $FreeBSD$
#

PORTNAME=	qpage
PORTVERSION=	3.2
CATEGORIES=	comms
#MASTER_SITES=	http://www.qpage.org/download/
MASTER_SITES=	http://people.FreeBSD.org/~fenner/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	joes@seaport.net

MAN1=		qpage.1

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/qpage.sh ]; then \
		${ECHO} "Install ${PREFIX}/etc/rc.d/qpage.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/qpage.sh; \
		${ECHO} "[ -x ${PREFIX}/bin/qpage ] && ${PREFIX}/bin/qpage -q10 && ${ECHO} -n ' qpage'" >> ${PREFIX}/etc/rc.d/qpage.sh; \
		${CHMOD} 751 ${PREFIX}/etc/rc.d/qpage.sh; \
	fi

.include <bsd.port.mk>
