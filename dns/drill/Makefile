# New ports collection makefile for:	drill
# Date created:        30 December 2004
# Whom:                Jaap Akkerhuis <jaap@NLnetLabs.nl
#
# $FreeBSD$
#

PORTNAME=	drill
PORTVERSION=	1.6.3
CATEGORIES=	dns
MASTER_SITES=	http://www.nlnetlabs.nl/downloads/ldns/
DISTNAME=	ldns-${PORTVERSION}

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	A dig style dnssec aware dns debugging tool

LIB_DEPENDS=	ldns.1:${PORTSDIR}/dns/ldns

MAN1=		drill.1

WRKSRC=		${WRKDIR}/ldns-${PORTVERSION}/${PORTNAME}
USE_OPENSSL=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB}
CFLAGS+=	${CPPFLAGS} -I${OPENSSLINC}
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MANPREFIX}/man

PLIST_FILES=	bin/drill

.include <bsd.port.mk>
