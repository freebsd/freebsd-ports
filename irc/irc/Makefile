# New ports collection makefile for:	Irc Server
# Date created:		23 August 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	irc
PORTVERSION=	2.10.3
CATEGORIES=	irc ipv6
MASTER_SITES=	ftp://ftp.funet.fi/pub/networking/services/irc/server/ \
		ftp://ftp.irc.org/irc/server/ \
		ftp://tau.ac.il/pub/unix/irc/server/ \
		ftp://ftp.ut.ee/pub/unix/irc/server/ \
		ftp://ftp.ntua.gr/pub/net/irc/server/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	The 'Internet Relay Chat' Server

# the NOTE command is disabled by default
# ENABLE_NOTE=yes

# Syslog-Facility to use for logging
# default:
SYSLOG_FACILITY=LOG_LOCAL5

SCRIPTS_ENV=	SYSLOG_FACILITY="${SYSLOG_FACILITY}"

MAN1=		irc.1
MAN5=		iauth.conf.5
MAN8=		ircd.8 iauth.8 ircdwatch.8

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/ircd
STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/ircd.sh

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+= --enable-ip6
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
		${ECHO} "Installing ${STARTUP_SCRIPT} startup file.";	\
		${INSTALL_SCRIPT} ${WRKDIR}/ircd.sh ${STARTUP_SCRIPT};\
	fi

.include <bsd.port.post.mk>
