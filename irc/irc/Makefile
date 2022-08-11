PORTNAME=	irc
PORTVERSION=	2.11.2p3
CATEGORIES=	irc
MASTER_SITES=	http://ftp.irc.org/ftp/irc/server/ \
		ftp://ftp.archive.de.uu.net/pub/mirrors/ftp.irc.org/server/ \
		ftp://ftp.nl.uu.net/pub/mirrors/ftp.irc.org/server/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The "Internet Relay Chat" Server

BROKEN_aarch64=		Fails to link: missing sbrk
BROKEN_riscv64=		Fails to link: missing sbrk

CONFLICTS_INSTALL=	charybdis ircd-hybrid Nefarious \
			ru-ircd-hybrid ircd-ru

USES=		tar:tgz
USE_RC_SUBR=	ircd
GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/ircd
CONFIGURE_WRKSRC=	${WRKSRC}/build
CONFIGURE_SCRIPT=	support/configure

OPTIONS_DEFINE=	IPV6
IPV6_CONFIGURE_ENABLE=	ipv6

post-configure:
	@${LN} -sf ${WRKSRC}/support/config.h.dist ${BUILD_WRKSRC}/config.h

.include <bsd.port.mk>
