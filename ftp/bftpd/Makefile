# New ports collection makefile for:	bftpd
# Date created:				7 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	bftpd
PORTVERSION=	1.0.18
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	http://www.bftpd.f2s.com/downloads/src/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
MAN8=		bftpd.8

pre-configure:
	${PERL} -pi -e "s@<wait.h>@<sys/wait.h>@g" ${WRKSRC}/commands.c
	${PERL} -pi -e "s@chmod 644 /var@#chmod 644 /var@g; \
			s@touch /var@#touch /var@g; \
			s@DESTDIR\)/etc@prefix\)/etc@g; \
			s@bftpd.conf @bftpd.conf.sample @g" ${WRKSRC}/Makefile.in
	${CP} ${WRKSRC}/bftpd.conf ${WRKSRC}/bftpd.conf.sample

.include <bsd.port.mk>
