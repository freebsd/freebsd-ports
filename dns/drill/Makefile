# New ports collection makefile for:	drill
# Date created:        30 December 2004
# Whom:                Jaap Akkerhuis <jaap@NLnetLabs.nl
#
# $FreeBSD$
#

PORTNAME=	drill
PORTVERSION=	0.9.2
CATEGORIES=	dns
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/drill/

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	A dig style dnssec aware dns debugging tool

MAN1=		drill.1
MANCOMPRESSED=	no

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_BZIP2=	yes
USE_OPENSSL=	yes
HAS_CONFIGURE=	yes
USE_GETOPT_LONG=yes
LDFLAGS+=	-L${OPENSSLLIB}
CFLAGS+=	-I${OPENSSLINC}
CONFIGURE_ARGS=	--prefix=${PREFIX}

PLIST_FILES=	bin/drill

.include <bsd.port.mk>
