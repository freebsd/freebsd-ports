# New ports collection makefile for: 	ngircd
# Date created:        1 May CEST 2003
# Whom:                Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	ngircd
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://download.berlios.de/ngircd/ \
		ftp://ftp.berlios.de/pub/ngircd/

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	Free open source daemon for Internet Relay Chat (IRC)

USE_RC_SUBR=	ngircd
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN5=		ngircd.conf.5
MAN8=		ngircd.8

OPTIONS=	TCP_WRAPPERS	"Enable TCP wrappers support"	on \
		SYSLOG		"Enable SYSLOG support"		on \
		ZLIB		"Enable ZLIB compression"	on \
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

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
