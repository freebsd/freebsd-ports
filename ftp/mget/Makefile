# ex:ts=8
# New ports collection makefile for:	mget
# Date created:			Sep 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mget
PORTVERSION=	1.3.0.2
CATEGORIES=	ftp ipv6
MASTER_SITES=	http://home.talkcity.com/LaGrangeLn/dbera/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

CFLAGS+=	-DHAS_HERROR -DHAVE_GETOPT_LONG -DHAVE_INET_NTOP -DHAVE_IPV6 \
		-I${LOCALBASE}/include ${PTHREAD_CFLAGS:S/"//g}
LDFLAGS=	-L${LOCALBASE}/lib -lgnugetopt ${PTHREAD_LIBS:S/"//g}

USE_REINPLACE=	yes

pre-patch:
	@find ${WRKSRC} -name '*.[ch]' | xargs ${REINPLACE_CMD} -e \
		's|#include <malloc.h>||g'

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o mget *.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mget ${PREFIX}/bin

.include <bsd.port.mk>
