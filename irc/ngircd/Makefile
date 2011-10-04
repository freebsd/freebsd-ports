# New ports collection makefile for: 	ngircd
# Date created:        1 May CEST 2003
# Whom:                Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	ngircd
PORTVERSION=	0.18
CATEGORIES=	irc ipv6
MASTER_SITES=	ftp://ftp.berlios.de/pub/%SUBDIR%/ \
		http://arthur.barton.de/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTVERSION=	${PORTVERSION:S/0.//}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Free open source daemon for Internet Relay Chat (IRC)

LICENSE=	GPLv2

USE_RC_SUBR=	ngircd
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

MAN5=		ngircd.conf.5
MAN8=		ngircd.8

OPTIONS=	TCP_WRAPPERS	"Enable TCP wrappers support"	on \
		SYSLOG		"Enable SYSLOG support"		on \
		ZLIB		"Enable ZLIB compression"	on \
		IPV6		"Enable IPV6"			on \
		OPENSSL		"Enable OpenSSL support"	off \
		GNUTLS		"Enable GnuTLS support"		off \
		IRCPLUS		"Enable IRC+ protocol"		on \
		IDENT		"Enable IDENT (AUTH) protocol support"	off \
		SNIFFER		"Enable IRC traffic sniffer"	off \
		DEBUG		"Show additional debug output"	off

.include <bsd.port.pre.mk>

.if exists(/usr/include/tcpd.h) && !defined(WITHOUT_TCP_WRAPPERS)
CONFIGURE_ARGS+=	--with-tcp-wrappers
.endif

.if defined(WITHOUT_SYSLOG)
CONFIGURE_ARGS+=	--without-syslog
.endif

.if defined(WITHOUT_ZLIB)
CONFIGURE_ARGS+=	--without-zlib
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if defined(WITH_OPENSSL)
CONFIGURE_ARGS+=	--with-openssl
.endif

.if defined(WITH_GNUTLS)
CONFIGURE_ARGS+=	--with-gnutls
USE_OPENSSL=yes
.endif

.if defined(WITHOUT_IRCPLUS)
CONFIGURE_ARGS+=	--disable-ircplus
.endif

.if defined(WITH_IDENT)
LIB_DEPENDS+=		ident.0:${PORTSDIR}/security/libident
CONFIGURE_ARGS+=	--with-ident
.endif

.if defined(WITH_SNIFFER)
CONFIGURE_ARGS+=	--enable-sniffer
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(NOPORTDOCS)
MAKE_ARGS+=		NOPORTDOCS=yes
.endif

.include <bsd.port.post.mk>
