# New ports collection makefile for:   znc
# Date created:        6 March 2008
# Whom:                elvstone@gmail.com
#
# $FreeBSD$
#

PORTNAME=	znc
PORTVERSION=	0.074
CATEGORIES=	irc ipv6
MASTER_SITES=	SF

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	An advanced IRC bouncer

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack
CONFIGURE_ARGS=	--disable-c-ares

OPTIONS=	DEBUG		"Enable debugging" off \
		IPV6		"Enable IPv6 support" off \
		OPENSSL		"Enable OpenSSL support" on \
		PERL		"Enable Perl support" on \
		SASL		"Enable SASL support" off

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if defined(WITH_OPENSSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
PLIST_SUB+=		OPENSSL=""
.else
CONFIGURE_ARGS+=	--disable-openssl
PLIST_SUB+=		OPENSSL="@comment "
.endif

.if defined(WITH_PERL)
USE_PERL5=		yes
PLIST_SUB+=		PERL=""
.else
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=		PERL="@comment "
.endif

.if defined(WITH_SASL)
LIB_DEPENDS+=		sasl2.2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--enable-sasl
CONFIGURE_ENV+=		LDFLAGS="-L${LOCALBASE}/lib"
PLIST_SUB+=		SASL=""
.else
PLIST_SUB+=		SASL="@comment "
.endif

MANCOMPREEED=	yes
MAN1=		znc.1.gz znc-buildmod.1.gz znc-config.1.gz

.include <bsd.port.post.mk>
