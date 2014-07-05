# Created by: Frank J. Laszlo <laszlof@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Nefarious
PORTVERSION=	1.2.0
CATEGORIES=	irc
MASTER_SITES=	SF/evilnet/${PORTNAME}%20IRCu/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC server used by evilnet based off of Undernet\'s ircu

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		tar:bzip2
HAS_CONFIGURE=	yes
PLIST_SUB+=	INSTALL_PREFIX=${INSTALL_PREFIX:S/${PREFIX}\///}

OPTIONS_DEFINE=	SSL CHROOT
CHROOT_DESC=	Chroot the irc daemon within INSTALL_PREFIX

SSL_CONFIGURE_ENABLE=	ssl

.include <bsd.port.options.mk>

.if defined(NEFARIUS_INSTALL_PREFIX)
INSTALL_PREFIX=${NEFARIUS_INSTALL_PREFIX}
.else
INSTALL_PREFIX=${PREFIX}/${PORTNAME}
.endif

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
.endif

.if ${PORT_OPTIONS:MCHROOT}
CONFIGURE_ARGS+=	--with-chroot=${INSTALL_PREFIX}
.endif

.if defined(NEFARIOUS_DOMAIN)
CONFIGURE_ARGS+=	--with-domain=${NEFARIOUS_DOMAIN}
.endif

CONFIGURE_ARGS+=	--prefix=${STAGEDIR}${INSTALL_PREFIX} \
			--mandir=${STAGEDIR}${MANPREFIX}/man

post-patch:
	@${REINPLACE_CMD} -e 's|@PREFIX@|${PREFIX}|g' ${WRKSRC}/configure

pre-configure:
	@${ECHO_CMD}
	@${ECHO_CMD} "User configurable options for ${PORTNAME}:"
	@${ECHO_CMD} "NEFARIOUS_INSTALL_PREFIX - Install location for Nefarious (default: ${PREFIX}/Nefarious)"
	@${ECHO_CMD} "NEFARIOUS_DOMAIN         - Domain to use for IRCd"
	@${ECHO_CMD}

.include <bsd.port.mk>
