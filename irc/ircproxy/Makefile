# New ports collection makefile for:   ircproxy
# Date created:        10 July 2003
# Whom:                Jonas Kvinge <jonas@night-light.net>
#
# $FreeBSD$
#

PORTNAME=	ircproxy
DISTVERSION=	1.2.42d.pre3
CATEGORIES=	irc
MASTER_SITES=	http://www.ircproxy.night-light.net/files/

MAINTAINER=	jonas@night-light.net
COMMENT=	An IRC proxy/bouncer daemon

GNU_CONFIGURE=		yes
CONFIGURE_WRKSRC=	${WRKSRC}/config

#
# Copy the freebsd port setup file to automatically generate setup.h
# So we dont need to do make config, I think this might be the best
# solution.
#
pre-build:
	@if [ ! -f ${WRKSRC}/config/setup-file ]; then ( \
		if [ ! -f ${WRKSRC}/setup/setup-freebsd ]; then ( ${ECHO} "Missing the setup-freebsd file!"; exit 1; ) fi; \
		${CP} ${WRKSRC}/setup/setup-freebsd ${WRKSRC}/setup/setup-file || exit 1; \
		cd ${WRKSRC}/setup; SETUP_BATCH=y SETUP_QUIET=y ${SH} ./setup || exit 1; \
		cd ${WRKSRC}/setup; ${SH} ./setup-makefile || exit 1; \
	) \
	fi;
	${CHMOD} u+x ${WRKSRC}/pkg-install || exit 1
	${CHMOD} u+x ${WRKSRC}/pkg-deinstall || exit 1

.include <bsd.port.mk>
