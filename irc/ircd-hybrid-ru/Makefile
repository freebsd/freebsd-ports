# New ports collection makefile for:	ircd-hybrid-ru
# Date Created:				2003.12.14
# Whom:					Evgueni V. Gavrilov <aquatique@rusunix.org>
#
# $FreeBSD$
#

PORTNAME=	ircd
PORTVERSION=	7.1
PORTREVISION=	5
CATEGORIES=	irc russian
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://rusunix.org/pub/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	ircd-hybrid-ru
PKGNAMESUFFIX=	-hybrid-ru
DISTNAME=	ircd-hybrid-ru-7.0rc12

MAINTAINER=	aquatique-ports@rambler.ru
COMMENT=	Russian version of well known hybrid IRC server

CONFLICTS=	ircd-hybrid-7* ircd-ru[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}
USE_OPENSSL=	yes
USE_BISON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/ircd-hybrid-ru --enable-kqueue

MANCOMPRESSED=	no
MAN8=		ircd.8

.if defined(WITHOUT_NLS)
BROKEN=		"Incorrect pkg-plist"
.endif

.if defined(WITH_SMALL_NET)
CONFIGURE_ARGS+=-enable-small-net
.endif

.if defined(NICKLENGTH)
CONFIGURE_ARGS+=--with-nicklen=${NICKLENGTH}
.endif

.if defined(TOPICLENGTH)
CONFIGURE_ARGS+=--with-topiclen=${TOPICLENGTH}
.endif

.if defined(MAXCLIENTS)
CONFIGURE_ARGS+=--with-maxclients=${MAXCLIENTS}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,"-g,",; s,-O2 -g,-O,' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,/modules/,/lib/ircd-hybrid-ru-modules/,' ${WRKSRC}/include/config.h
	@${REINPLACE_CMD} -e 's,/etc,/etc/ircd-hybrid-ru,' ${WRKSRC}/include/config.h
	@${REINPLACE_CMD} -e 's,IRCD_PREFIX "/logs","/var/log/ircd-hybrid-ru",' ${WRKSRC}/include/config.h
	@${FIND} ${WRKSRC} -type f -name Makefile.in -print0 | ${XARGS} -0 ${REINPLACE_CMD} \
		-e "s,/modules,/lib/ircd-hybrid-ru-modules,"

pre-extract:
	@${ECHO_MSG} "* * * Build options for ircd-hybrid-ru * * *"
	@${ECHO_MSG} "Issue make WITH_SMALL_NET=yes to build server optimized for small network"
	@${ECHO_MSG} "You can define maximum nick length. For example make NICKLENGTH=46 (default is 30)"
	@${ECHO_MSG} "You can define maximum topic length. For example make TOPICLENGTH=254 (default is 120; maximum is 390)"
	@${ECHO_MSG} "You can define maximum number of connections for ircd. For example make MAXCLIENTS=512"

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${REINPLACE_CMD} -e 's,ircd/etc/codepage,etc/ircd-hybrid-ru/codepage,' ${WRKSRC}/doc/example.conf
	@${REINPLACE_CMD} -e 's,/ircd/modules,/lib/ircd-hybrid-ru-modules,' ${WRKSRC}/doc/example.conf
	@${REINPLACE_CMD} -e 's,logs/,/var/log/ircd-hybrid-ru/,' ${WRKSRC}/doc/example.conf

post-install:
	@${INSTALL_SCRIPT} -m 555 ${FILESDIR}/ircd-hybrid-ru.sh.sample ${PREFIX}/etc/rc.d
	@${CHOWN} -R ircdru:ircdru ${PREFIX}/etc/ircd-hybrid-ru
	@${CHOWN} -R ircdru:ircdru /var/log/ircd-hybrid-ru
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/RELNOTE* ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/server-version-info ${DOCSDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
