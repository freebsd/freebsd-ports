# Created by: Frank J. Laszlo <laszlof@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Nefarious
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	SF/evilnet/${PORTNAME}%20IRCu/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC server used by evilnet based off of Undernet's ircu

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USES=		tar:bzip2
HAS_CONFIGURE=	yes
BINMODE=	711
PLIST_SUB+=	INSTALL_PREFIX=${INSTALL_PREFIX:S/${PREFIX}\///}

OPTIONS_DEFINE=	SSL CHROOT DOCS
CHROOT_DESC=	Chroot the irc daemon within INSTALL_PREFIX

SSL_CONFIGURE_ENABLE=	ssl
SSL_USE=		OPENSSL=yes
CHROOT_CONFIGURE_ON=	--with-chroot=${INSTALL_PREFIX}

.if defined(NEFARIUS_INSTALL_PREFIX)
INSTALL_PREFIX=${NEFARIUS_INSTALL_PREFIX}
.else
INSTALL_PREFIX=${PREFIX}/${PORTNAME}
.endif
STAGEPREFIX=${STAGEDIR}${INSTALL_PREFIX}

.if defined(NEFARIOUS_DOMAIN)
CONFIGURE_ARGS+=	--with-domain=${NEFARIOUS_DOMAIN}
.endif

CONFIGURE_ARGS+=	--prefix=${INSTALL_PREFIX} \
			--mandir=${MANPREFIX}/man

SYMLINKS=	admin away challenge invite names nick version \
		join kick motd oper part quit time cnotice \
		cprivmsg credits copyright info ircops ison links \
		lusers map notice pass rules silence sethost topic \
		userhost userip wallchops wallhops wallvoices whois \
		commands

post-extract:
	@${FIND} ${WRKSRC} -type d -name ".svn" | ${XARGS} ${RM} -rf

post-patch:
	@${REINPLACE_CMD} -e 's|@PREFIX@|${PREFIX}|g' ${WRKSRC}/configure

pre-configure:
	@${ECHO_CMD} "User configurable options for ${PORTNAME}:"
	@${ECHO_CMD} "NEFARIOUS_INSTALL_PREFIX - Install location for Nefarious"
	@${ECHO_CMD} "                           (default: ${PREFIX}/Nefarious)"
	@${ECHO_CMD} "NEFARIOUS_DOMAIN         - Domain to use for IRCd"

do-install:
	@${MKDIR} ${STAGEPREFIX}/bin ${STAGEPREFIX}/lib/help
	${INSTALL_PROGRAM} ${WRKSRC}/ircd/ircd ${STAGEPREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/ircd/chkconf ${STAGEPREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf ${STAGEPREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/doc/ircd.8 ${STAGEDIR}${MANPREFIX}/man/man8
	(cd ${WRKSRC}/help && \
		${COPYTREE_SHARE} users ${STAGEPREFIX}/lib/help && \
		${COPYTREE_SHARE} opers ${STAGEPREFIX}/lib/help)
	(cd ${STAGEPREFIX}/lib/help/opers && ${CP} ${SYMLINKS} ../users)

post-install:
	${STRIP_CMD} ${STAGEPREFIX}/bin/chkconf

.include <bsd.port.mk>
