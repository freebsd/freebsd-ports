# New ports collection makefile for:	Irc Server
# Date created:		23 August 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	irc
PORTVERSION=	2.11.1.1
CATEGORIES=	irc ipv6
MASTER_SITES=	ftp://ftp.irc.org/irc/server/ \
		ftp://ftp2.nchu.edu.tw/UNIX/IRC/server/ \
		ftp://ftp.plig.net/pub/irc/ftp.irc.org/server/ \
		ftp://ftp.archive.de.uu.net/pub/mirrors/ftp.irc.org/server/ \
		ftp://ftp.iway.fr/pub/mirrors/ftp.irc.org/server/ \
		ftp://ftp.nl.uu.net/pub/mirrors/ftp.irc.org/server/
DISTNAME=	${PORTNAME}2.11.1p1
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The "Internet Relay Chat" Server

# the NOTE command is disabled by default
# ENABLE_NOTE=yes

# Syslog-Facility to use for logging
# default:
SYSLOG_FACILITY=LOG_LOCAL5

SCRIPTS_ENV=	SYSLOG_FACILITY="${SYSLOG_FACILITY}"

MAN5=		iauth.conf.5
MAN8=		ircd.8 iauth.8 ircdwatch.8

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/ircd
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/ircd.sh

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=	--enable-ip6
.endif

pre-build:
	@${RM} -f ${WRKDIR}/ircd.sh
	@${SED} -e "s;%%PREFIX%%;${PREFIX};g" ${FILESDIR}/ircd.sh > ${WRKDIR}/ircd.sh

do-build:
	@(cd ${WRKSRC}/${MACHINE_ARCH}-unknown-freebsd${OSREL}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
	@(cd ${WRKSRC}/${MACHINE_ARCH}-unknown-freebsd${OSREL} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})

post-install:
	@if [ ! -f ${STARTUP_SCRIPT} ]; then				\
		${ECHO_MSG} "Installing ${STARTUP_SCRIPT} startup file.";	\
		${INSTALL_SCRIPT} ${WRKDIR}/ircd.sh ${STARTUP_SCRIPT};\
	fi

.include <bsd.port.post.mk>
