# New ports collection makefile for:	qpage
# Date created:		02 Aug 1997
# Whom:			joes@seaport.net
#
# $FreeBSD$
#

PORTNAME=	qpage
PORTVERSION=	3.3
PORTREVISION=	3
CATEGORIES=	comms
MASTER_SITES=	http://www.qpage.org/download/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SNPP client/server for sending messages to an alphanumeric pager

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=		qpage.1

post-patch:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
		${WRKSRC}/qpage.man \
		${WRKSRC}/config.input \
		${WRKSRC}/config.h.in

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/qpage.sh ]; then \
		${ECHO_MSG} "Install ${PREFIX}/etc/rc.d/qpage.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/qpage.sh \
			${PREFIX}/etc/rc.d/qpage.sh; \
	fi
	@if [ ! -f ${PREFIX}/etc/qpage-example.cf ]; then \
		${ECHO_MSG} "Install ${PREFIX}/etc/qpage-example.cf file."; \
		${INSTALL_SCRIPT} -m 640 ${WRKDIR}/${PORTNAME}-${PORTVERSION}/example.cf \
			${PREFIX}/etc/qpage-example.cf; \
	fi
	${MKDIR} /var/spool/${PORTNAME}
	${CHOWN} uucp:dialer /var/spool/${PORTNAME}
	${CHMOD} 0775 /var/spool/${PORTNAME}

.include <bsd.port.mk>
