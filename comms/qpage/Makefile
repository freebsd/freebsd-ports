# New ports collection makefile for:	qpage
# Date created:		02 Aug 1997
# Whom:			joes@seaport.net
#
# $FreeBSD$
#

PORTNAME=	qpage
PORTVERSION=	3.3
CATEGORIES=	comms
MASTER_SITES=	http://www.qpage.org/download/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	joes@seaport.net

GNU_CONFIGURE=	yes

MAN1=		qpage.1

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/qpage.sh ]; then \
		${ECHO} "Install ${PREFIX}/etc/rc.d/qpage.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/qpage.sh \
			${PREFIX}/etc/rc.d/qpage.sh; \
	fi
	@if [ ! -f ${PREFIX}/etc/qpage-example.cf ]; then \
		${ECHO} "Install ${PREFIX}/etc/qpage-example.cf file."; \
		${INSTALL_SCRIPT} -m 660 ${WRKDIR}/${PORTNAME}-${PORTVERSION}/example.cf \
			${PREFIX}/etc/qpage-example.cf; \
	fi

.include <bsd.port.mk>
