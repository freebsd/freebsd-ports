# New ports collection makefile for:    evangeline
# Date created:                         1 Mar 2005
# Whom:         			"Edini" <ports@edini.net>
#
# $FreeBSD$
#

PORTNAME=	evangeline
PORTVERSION=	1.1.0
CATEGORIES=	irc tcl84
MASTER_SITES=	http://www.averse.piasta.pl/_data/evangeline/1.1.0/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC Bot based on Eggdrop

LIB_DEPENDS=	tcl84.1:${PORTSDIR}/lang/tcl84

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
IS_INTERACTIVE=	yes

OPTIONS=	IPV6 "Enable IPv6 support" off \
		CRYPT "Enable Encryption" on

.include <bsd.port.pre.mk>

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITHOUT_CRYPT)
CONFIGURE_ARGS+=	--disable-crypt
.else
CONFIGURE_ARGS+=	--enable-crypt
.endif

PLIST_FILES=	bin/evangeline

.include <bsd.port.post.mk>
