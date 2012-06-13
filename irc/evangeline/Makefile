# New ports collection makefile for:    evangeline
# Date created:                         1 Mar 2005
# Whom:         			"Edini" <ports@edini.net>
#
# $FreeBSD$
#

PORTNAME=	evangeline
PORTVERSION=	1.1.4
CATEGORIES=	irc tcl
MASTER_SITES=	http://www.averse.piasta.pl/_data/evangeline/${PORTVERSION}/
DISTFILES=	${PORTNAME}-${PORTVERSION}-b1.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC Bot based on Eggdrop

LIB_DEPENDS=	tcl84.1:${PORTSDIR}/lang/tcl84

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
IS_INTERACTIVE=	yes

OPTIONS_DEFINe=	IPV6 CRYPT
OPTIONS_DEFAULT=	CRYPT
CRYPT_DESC=	Enable Encryption

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MCRYPT}
CONFIGURE_ARGS+=	--enable-crypt
.else
CONFIGURE_ARGS+=	--disable-crypt
.endif

PLIST_FILES=	bin/evangeline

.include <bsd.port.mk>
