# New ports collection makefile for:   sms_client
# Date created:        11 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		sms_client
PORTVERSION=		3.0.2
PORTREVISION=		2
CATEGORIES=		comms
MASTER_SITES=		http://www.smsclient.org/download/smsclient-3.0-testing/ \
			http://www.mirrors.wiretapped.net/security/host-monitoring/sms-client/

MAINTAINER=		ports@FreeBSD.org
COMMENT=	A simple UNIX SMS client to send messages to phones or pagers

HAS_CONFIGURE=		yes

MAN1=			sms_client.1

post-configure:
	@${SED} -e 's@gcc@${CC}@g' -e 's@-Wall@${CFLAGS} -Wall@g' \
		${FILESDIR}/Makefile.config > ${WRKSRC}/Makefile.config

post-patch:
	@${MV} ${WRKSRC}/sms/services/vodafone_autralia \
		${WRKSRC}/sms/services/vodafone_australia
	@${RM} ${WRKSRC}/sms/services/att_web.orig

.include <bsd.port.mk>
