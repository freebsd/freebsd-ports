PORTNAME=	utdns
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	dns

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Proxy UDP/DNS to TCP/DNS
WWW=		https://www.cypherpunk.at/2013/04/dnsudp-to-tcp-translator/

LICENSE=	GPLv3

USES=		autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	rahra
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes

CFLAGS+=	-DSOCK_NONBLOCK=1

SUB_LIST=	PORTNAME=${PORTNAME}

PLIST_FILES=	bin/utdns

.include <bsd.port.mk>
