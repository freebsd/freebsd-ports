# Created by: David Taylor <davidt@yadt.co.uk>
# $FreeBSD$
#

PORTNAME=	ircd-hybrid
PORTVERSION=	8.0.4
CATEGORIES=	irc ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	db@FreeBSD.org
COMMENT=	A fast irc daemon with a number of new features

MAN8=		ircd.8
INSTALL_IGNORES=	ircu-* ircd-rat* charby*

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

USERS=		ircd
GROUPS=		${USERS}

USE_RC_SUBR=	ircd-hybrid
SUB_FILES=	pkg-message
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

#
# User Configurable Variables
#
# PREFIX		- Where to install ircd-hybrid. Default is /usr/local
# WITH_OPENSSL	- Enable openssl. Allows use of CHALLENGE and encrypted links.
# WITHOUT_ASSERT	- Disable parts of the debugging code.
# WITH_HALFOPS		- Enable halfops on the server.
# NICKLEN		- Nick length. Default is 9. Must be consistant across the network.

.if defined(PREFIX)
CONFIGURE_ARGS+=	--prefix=${PREFIX}
.endif

.if defined(WITH_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--enable-openssl=${OPENSSLBASE}
.endif

.if defined(WITH_HALFOPS)
CONFIGURE_ARGS+=	--enable-halfops
.endif

.if defined(WITHOUT_ASSERT)
CONFIGURE_ARGS+=	--disable-assert
.endif

.if defined(NICKLEN)
CONFIGURE_ARGS+=	--with-nicklen=${NICKLEN}
.endif

CONFIGURE_ARGS+=	\
	--sysconfdir=${PREFIX}/etc/ircd-hybrid \
	--prefix=${LOCAL} \
	--datarootdir=${PREFIX}/share/${PORTNAME}-${PORTVERSION}

pre-su-install:
	${MKDIR} ${PREFIX}/etc/ircd-hybrid ${PREFIX}/share/${PORTNAME}-${PORTVERSION}
	${MKDIR} ${PREFIX}/share/${PORTNAME}-${PORTVERSION}/help/

post-install:
	${MKDIR} /var/run/ircd
	${CHOWN} ircd:ircd /var/run/ircd
	${INSTALL_SCRIPT} ${WRKSRC}/doc/example.quick.conf ${PREFIX}/etc/ircd-hybrid
	${INSTALL_SCRIPT} ${WRKSRC}/doc/example.efnet.conf ${PREFIX}/etc/ircd-hybrid
	${INSTALL_SCRIPT} ${WRKSRC}/doc/example.conf ${PREFIX}/etc/ircd-hybrid
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
