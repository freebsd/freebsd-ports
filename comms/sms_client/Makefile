# New ports collection makefile for:   sms_client
# Date created:        11 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=       	sms_client
PORTVERSION=		3.0.2
CATEGORIES=     	comms
MASTER_SITES=   	http://www.styx.demon.co.uk/archive/

MAINTAINER=		greid@ukug.uk.freebsd.org

HAS_CONFIGURE=		yes

MAN1=			sms_client.1

post-configure:
	${SED} -e 's@gcc@${CC}@g' -e 's@-Wall@${CFLAGS} -Wall@g' \
		${FILESDIR}/Makefile.config > ${WRKSRC}/Makefile.config

.include <bsd.port.mk>
