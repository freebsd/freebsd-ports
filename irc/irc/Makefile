# Created by: torstenb
# $FreeBSD$

PORTNAME=	irc
PORTVERSION=	2.11.2p3
CATEGORIES=	irc ipv6
MASTER_SITES=	http://ftp.irc.org/ftp/irc/server/ \
		ftp://ftp.archive.de.uu.net/pub/mirrors/ftp.irc.org/server/ \
		ftp://ftp.nl.uu.net/pub/mirrors/ftp.irc.org/server/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	johans@FreeBSD.org
COMMENT=	The "Internet Relay Chat" Server

CONFLICTS_INSTALL=	charybdis-[0-9]* ircd-hybrid-[0-9]* Nefarious-[0-9]* \
			ru-ircd-hybrid-[0-9]* ircd-ru-[0-9]*

USE_RC_SUBR=	ircd
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/ircd
BUILD_WRKSRC=		${WRKSRC}/build
INSTALL_WRKSRC=		${BUILD_WRKSRC}
CONFIGURE_WRKSRC=	${BUILD_WRKSRC}

OPTIONS_DEFINE=	IPV6
OPTIONS_DEFAULT=IPV6
IPV6_CONFIGURE_ENABLE=	ipv6

pre-configure:
	@${MKDIR} ${BUILD_WRKSRC}
	${CP} -p ${WRKSRC}/support/configure ${BUILD_WRKSRC}
	${CP} -p ${WRKSRC}/support/config.h.dist ${BUILD_WRKSRC}/config.h

.include <bsd.port.mk>
