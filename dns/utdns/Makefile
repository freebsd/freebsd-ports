# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	utdns
PORTVERSION=	1.0
DISTVERSIONSUFFIX=	.r1437
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	https://www.cypherpunk.at/download/utdns/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Proxy UDP/DNS to TCP/DNS

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}

SUB_LIST=	PORTNAME=${PORTNAME}

CFLAGS+=	-DSOCK_NONBLOCK=1

PLIST_FILES=	bin/utdns

.include <bsd.port.mk>
