# New ports collection makefile for:   sms_client
# Date created:        11 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		sms_client
PORTVERSION=		3.0.2
PORTREVISION=		1
CATEGORIES=		comms
MASTER_SITES=		http://www.styx.demon.co.uk/archive/

MAINTAINER=		ports@FreeBSD.org
COMMENT=	A simple UNIX SMS client to send messages to phones or pagers

HAS_CONFIGURE=		yes

MAN1=			sms_client.1

post-configure:
	${SED} -e 's@gcc@${CC}@g' -e 's@-Wall@${CFLAGS} -Wall@g' \
		${FILESDIR}/Makefile.config > ${WRKSRC}/Makefile.config

post-patch:
	${MV} ${WRKSRC}/sms/services/vodafone_autralia \
		${WRKSRC}/sms/services/vodafone_australia

.include <bsd.port.mk>
