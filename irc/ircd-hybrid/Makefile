# New ports collection makefile for:	ircd-hybrid
# Date Created:				2001-10-07
# Whom:					David Taylor <davidt@yadt.co.uk>
#
# $FreeBSD$
#

PORTNAME=	ircd-hybrid
PORTVERSION=	7.2.1
CATEGORIES=	irc ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	db@db.net
COMMENT=	A fast irc daemon with a number of new features

MAN8=		ircd.8

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

USE_RC_SUBR=	ircd-hybrid.sh
SUB_FILES=	pkg-message
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

#
# User Configurable Variables
#
# PREFIX		- Where to install ircd-hybrid. Default is /usr/local
# WITH_OPENSSL	- Enable openssl. Allows use of CHALLENGE and encrypted links.
# WITHOUT_SHARED_MODULES - Disable shared modules. More secure but reduces flexability.
# WITHOUT_ASSERT	- Disable parts of the debugging code.
# WITH_SMALL_NET	- Tunes the memory allocation for small networks.
# WITH_HALFOPS		- Enable halfops on the server.
# NICKLEN		- Nick length. Default is 9. Must be consistant across the network.
# MAXCLIENTS		- Set this to the maximum number of clients supported by this server. Default is 200

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

.if defined(WITHOUT_SHARED_MODULES)
CONFIGURE_ARGS+=	--disable-shared-modules
PLIST_SUB+=		SHAREDMODULES="@comment "
.else
PLIST_SUB+=		SHAREDMODULES=""
.endif

.if defined(WITHOUT_ASSERT)
CONFIGURE_ARGS+=	--disable-assert
.endif

.if defined(WITH_SMALL_NET)
CONFIGURE_ARGS+=	--enable-small-net
.endif

.if defined(NICKLEN)
CONFIGURE_ARGS+=	--with-nicklen=${NICKLEN}
.endif

.if defined(MAXCLIENTS)
CONFIGURE_ARGS+=	--with-maxclients=${MAXCLIENTS}
.endif

CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/ircd-hybrid \
	--moduledir=${PREFIX}/share/${PORTNAME}-${PORTVERSION}/modules \
	--automoduledir=${PREFIX}/share/${PORTNAME}-${PORTVERSION}/modules/autoload \
	--uhelpdir=${PREFIX}/share/${PORTNAME}-${PORTVERSION}/help/users \
	--ohelpdir=${PREFIX}/share/${PORTNAME}-${PORTVERSION}/help/opers \
	--messagedir=${PREFIX}/share/${PORTNAME}-${PORTVERSION}/messages \

pre-install:
	${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	${MKDIR} ${PREFIX}/etc/ircd-hybrid ${PREFIX}/share/${PORTNAME}-${PORTVERSION}
	${MKDIR} ${PREFIX}/share/${PORTNAME}-${PORTVERSION}/help/
	${MKDIR} /var/run/ircd
	${CHOWN} ircd:ircd /var/run/ircd

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/etc/example.conf.quick ${PREFIX}/etc/ircd-hybrid
	${INSTALL_SCRIPT} ${WRKSRC}/etc/example.efnet.conf ${PREFIX}/etc/ircd-hybrid
	${INSTALL_SCRIPT} ${WRKSRC}/etc/simple.conf ${PREFIX}/etc/ircd-hybrid
	@${CHOWN} ircd:ircd /var/log/ircd
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
