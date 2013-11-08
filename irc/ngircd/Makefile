# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	ngircd
PORTVERSION=	21
PORTEPOCH=	1
CATEGORIES=	irc ipv6
MASTER_SITES=	ftp://ftp.berlios.de/pub/%SUBDIR%/ \
		http://arthur.barton.de/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free open source daemon for Internet Relay Chat (IRC)

LICENSE=	GPLv2

USE_RC_SUBR=	ngircd
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	DOCS TCP_WRAPPERS SYSLOG ZLIB IPV6 OPENSSL GNUTLS IRCPLUS IDENT SNIFFER DEBUG
OPTIONS_DEFAULT=TCP_WRAPPERS SYSLOG ZLIB IPV6 IRCPLUS
NO_OPTIONS_SORT=yes
TCP_WRAPPERS_DESC=	Enable TCP wrappers support
SYSLOG_DESC=		Enable syslog() support
ZLIB_DESC=		Enable ZLIB compression
IRCPLUS_DESC=		Enable IRC+ protocol
IDENT_DESC=		Enable IDENT (AUTH) protocol support
SNIFFER_DESC=		Enable IRC traffic sniffer
DEBUG_DESC=		Show additional debug output

.include <bsd.port.options.mk>

.if exists(/usr/include/tcpd.h) && !defined(WITHOUT_TCP_WRAPPERS)
CONFIGURE_ARGS+=	--with-tcp-wrappers
.endif

.if empty(PORT_OPTIONS:MSYSLOG)
CONFIGURE_ARGS+=	--without-syslog
.endif

.if empty(PORT_OPTIONS:MZLIB)
CONFIGURE_ARGS+=	--without-zlib
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if ${PORT_OPTIONS:MOPENSSL}
CONFIGURE_ARGS+=	--with-openssl
USE_OPENSSL=yes
.endif

.if ${PORT_OPTIONS:MGNUTLS}
CONFIGURE_ARGS+=	--with-gnutls
LIB_DEPENDS+=		gnutls:${PORTSDIR}/security/gnutls
.endif

.if empty(PORT_OPTIONS:MIRCPLUS)
CONFIGURE_ARGS+=	--disable-ircplus
.endif

.if ${PORT_OPTIONS:MIDENT}
LIB_DEPENDS+=		ident:${PORTSDIR}/security/libident
CONFIGURE_ARGS+=	--with-ident
.endif

.if ${PORT_OPTIONS:MSNIFFER}
CONFIGURE_ARGS+=	--enable-sniffer
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ! ${PORT_OPTIONS:MDOCS}
MAKE_ARGS+=		NOPORTDOCS=yes
.endif

.include <bsd.port.mk>
