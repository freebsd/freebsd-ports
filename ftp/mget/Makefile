# ex:ts=8
# New ports collection makefile for:	mget
# Date created:			Sep 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mget
PORTVERSION=	1.4.1
CATEGORIES=	ftp ipv6
MASTER_SITES=	http://www.cse.iitk.ac.in/users/dbera/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi Threaded Wget

PLIST_FILES=	bin/mget
USE_GETOPT_LONG=	yes
CFLAGS+=	-DHAS_HERROR -DHAVE_GETOPT_LONG -DHAVE_INET_NTOP -DHAVE_IPV6 \
		${PTHREAD_CFLAGS:S/"//g}
LDFLAGS+=	${PTHREAD_LIBS:S/"//g}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} -o mget *.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mget ${PREFIX}/bin

.include <bsd.port.mk>
