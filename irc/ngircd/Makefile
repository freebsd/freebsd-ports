# New ports collection makefile for: 	ngircd
# Date created:        1 May CEST 2003
# Whom:                Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	ngircd
PORTVERSION=	0.7.7
CATEGORIES=	irc
MASTER_SITES=	http://download.berlios.de/ngircd/ \
		ftp://ftp.berlios.de/pub/ngircd/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Free open source daemon for Internet Relay Chat (IRC)

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if exists(/usr/include/tcpd.h)
WITH_TCP_WRAPPERS=	yes
CONFIGURE_ARGS+=	--with-tcp-wrappers
.endif

.if defined(WITHOUT_SYSLOG)
CONFIGURE_ARGS+=	--without-syslog
.endif

.if defined(WITHOUT_ZLIB)
CONFIGURE_ARGS+=	--without-zlib
.endif

MAN5=		ngircd.conf.5
MAN8=		ngircd.8

pre-configure:
	@${ECHO_MSG} ""
.if defined(WITH_TCP_WRAPPERS)
	@${ECHO_MSG} "Enabling TCP wrappers support"
	@${ECHO_MSG} ""
.endif
.if defined(WITHOUT_SYSLOG)
	@${ECHO_MSG} "Disable syslog support"
	@${ECHO_MSG} ""
.endif
.if defined(WITHOUT_ZLIB)
	@${ECHO_MSG} "Disable zlib suppot"
	@${ECHO_MSG} ""
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
