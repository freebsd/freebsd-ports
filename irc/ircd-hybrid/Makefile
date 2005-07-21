# New ports collection makefile for:	ircd-hybrid
# Date Created:				2001-10-07
# Whom:					David Taylor <davidt@yadt.co.uk>
#
# $FreeBSD$
#

PORTNAME=	ircd-hybrid
PORTVERSION=	7.0.2
PORTREVISION=	2
CATEGORIES=	irc ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	ircd-hybrid
EXTRACT_SUFX=	.tgz

MAINTAINER=	so14k@so14k.com
COMMENT=	An irc daemon with a number of new features

MAN8=		ircd.8

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

PLIST_SUB+=	PORTVERSION=${PORTVERSION}
EXTRA_PATCHES=	${WRKDIR}/patch-include-config.h

#
# User Configurable Variables
#
# PREFIX		- Where to install ircd-hybrid. Default is /usr/local/ircd
# WITH_KQUEUE		- Use kqueue(2) instead of poll(2).
# WITH_OPENSSL	- Enable openssl. Allows use of CHALLENGE and encrypted links.
# WITH_IPV6		- Enable IPv6 Support.
# WITHOUT_SHARED_MODULES - Disable shared modules. More secure but reduces flexability.
# WITHOUT_ASSERT	- Disable parts of the debugging code.
# WITH_SMALL_NET	- Tunes the memory allocation for small networks.
# NICKLEN		- Nick length. Default is 9. Must be consistant across the network.
# MAXCLIENTS		- Set this to the maximum number of clients supported by this server. Default is 200

.if defined(PREFIX)
CONFIGURE_ARGS+=	--prefix=${PREFIX}
.endif

.if defined(WITH_KQUEUE)
CONFIGURE_ARGS+=	--enable-kqueue
.endif

.if defined(WITH_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--enable-openssl=${OPENSSLINC}/openssl
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
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
	--mandir=${MANPREFIX}/man \
	--uhelpdir=${PREFIX}/share/${PORTNAME}-${PORTVERSION}/help/users \
	--ohelpdir=${PREFIX}/share/${PORTNAME}-${PORTVERSION}/help/opers \
	--messagedir=${PREFIX}/share/${PORTNAME}-${PORTVERSION}/messages \

pre-patch:
	@${SED} -e "s#%%PORTVERSION%%#${PORTVERSION}#" ${FILESDIR}/include-config.h.pre-patch > ${WRKDIR}/patch-include-config.h

post-patch:
	@${REINPLACE_CMD} -e "s#man8#man/man8#" ${WRKSRC}/doc/Makefile.in
	@${MV} ${WRKSRC}/doc/ircd.motd ${WRKSRC}/doc/ircd.motd.sample
	@${MV} ${WRKSRC}/doc/kline.conf ${WRKSRC}/doc/kline.conf.sample
	@${MV} ${WRKSRC}/doc/dline.conf ${WRKSRC}/doc/dline.conf.sample

pre-install:
	${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	${MKDIR} ${PREFIX}/etc/ircd-hybrid ${PREFIX}/share/${PORTNAME}-${PORTVERSION}
	${MKDIR} ${PREFIX}/share/${PORTNAME}-${PORTVERSION}/help/

post-install:
	@${SED} -e "s#%PREFIX%#${PREFIX}#" ${FILESDIR}/ircd-hybrid.sh > ${WRKDIR}/ircd-hybrid.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/ircd-hybrid.sh ${PREFIX}/etc/rc.d
	@${SED} -e "s#/usr/local/#${PREFIX}/#" ${PKGMESSAGE}

.include <bsd.port.mk>
