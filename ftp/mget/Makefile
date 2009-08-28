# ex:ts=8
# New ports collection makefile for:	mget
# Date created:			Sep 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mget
PORTVERSION=	1.4.2
CATEGORIES=	ftp ipv6
MASTER_SITES=	http://cs-people.bu.edu/dbera/projects/mget/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multithreaded commandline web-download manager

CFLAGS+=	-DHAS_HERROR -DHAVE_GETOPT_LONG -DHAVE_INET_NTOP -DHAVE_IPV6 \
		${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

MAN1=		mget.1
PLIST_FILES=	bin/mget

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} -o mget *.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mget ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mget.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
