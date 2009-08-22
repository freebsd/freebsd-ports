# New ports collection makefile for:	tr-ircd
# Date created:         Sat May 4 15:54:47 CET 2002
# Whom:                 Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	tr-ircd
PORTVERSION=	5.7.3
PORTREVISION=	1
CATEGORIES=	irc ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-ircd/trircd-${PORTVERSION}-release
DISTNAME=	${PORTNAME:S/-//}-release-${PORTVERSION}-r

MAINTAINER=	mm@FreeBSD.org
COMMENT=	An irc daeemon based on Bahamut and hybrid-7

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

TRIRCD_MAXCLIENTS?=	128

TRIRCD_USER?=	trircd
TRIRCD_GROUP?=	trircd
TRIRCD_RUNDIR?=	/var/run/tr-ircd
TRIRCD_LOGDIR?=	/var/log/tr-ircd
TRIRCD_CONFDIR?=	${PREFIX}/etc/tr-ircd
TRIRCD_LIBDIR=	${PREFIX}/lib/tr-ircd
TRIRCD_INCLUDEDIR=	${PREFIX}/include/tr-ircd

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--localstatedir=${TRIRCD_RUNDIR} \
		--sysconfdir=${TRIRCD_CONFDIR} \
		--libdir=${TRIRCD_LIBDIR} \
		--includedir=${TRIRCD_INCLUDEDIR} \
		--datadir=${DATADIR} \
		--enable-network-loop=kqueue \
		--with-fakehost-postfix=COM \
		--with-maxclients=${TRIRCD_MAXCLIENTS}

CONFIGURE_ENV+=	MD5SUMS="\"${MD5} -r\""

USE_RC_SUBR=	trircd

SUB_LIST+=	TRIRCD_USER="${TRIRCD_USER}" TRIRCD_GROUP="${TRIRCD_GROUP}" \
		TRIRCD_RUNDIR="${TRIRCD_RUNDIR}" TRIRCD_LOGDIR="${TRIRCD_LOGDIR}" \
		TRIRCD_CONFDIR="${TRIRCD_CONFDIR}"

SUB_FILES+=	pkg-install pkg-deinstall pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
PKGMESSAGE=	${WRKDIR}/pkg-message

.if !defined(NO_INSTALL_MANPAGES)
MAN8=		tr-ircd.8
.endif

DOCS=		AUTHORS ChangeLog INSTALL LICENSE README.FIRST README.HTTPD \
		README.OPM RELNOTES TODO

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--enable-openssl=${OPENSSLBASE}
.endif

.include <bsd.port.pre.mk>

PW?=		/usr/sbin/pw
SUB_LIST+=	MKDIR="${MKDIR}" PW="${PW}" CHMOD="${CHMOD}" CHOWN="${CHOWN}"

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,-O2,${CFLAGS}," ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s, ircpasswd,tr-ircpasswd," \
		-e "s,/home/ircd/lib,${TRIRCD_LIBDIR}," \
		-e "s,/home/ircd/ircd5/lib/,${TRIRCD_LIBDIR}," \
		-e "s,/home/ircd/ircd5/etc/,${TRIRCD_CONFDIR}," \
		-e "s,/home/ircd/var/run/tr-ircd,${TRIRCD_RUNDIR}," \
		${WRKSRC}/doc/configuration/example.conf
	@${REINPLACE_CMD} -e "s,@localstatedir@/lib/tr-ircd,${TRIRCD_RUNDIR}," \
		${WRKSRC}/tools/irandom.sh.in ${WRKSRC}/tools/isslconfig.sh.in
	@${REINPLACE_CMD} -e "s,@bindir@,${DATADIR}/tools," ${WRKSRC}/tools/Makefile.in

post-configure:
	@${REINPLACE_CMD} -e "s,/var/log/tr-ircd,${TRIRCD_LOGDIR}," ${WRKSRC}/include/ircpath.h

pre-install:
	@${SH} ${PKGINSTALL}

post-install:
	@${MKDIR} ${TRIRCD_CONFDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/configuration/example.conf ${TRIRCD_CONFDIR}/ircd.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/doc/configuration/example-ihttpd.conf ${TRIRCD_CONFDIR}/ihttpd.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/doc/configuration/example-maskfile.conf ${TRIRCD_CONFDIR}/maskfile.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/doc/configuration/example-socks.conf ${TRIRCD_CONFDIR}/socks.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/doc/configuration/ircdssl.conf ${TRIRCD_CONFDIR}/ircdssl.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/doc/configuration/ircd.motd ${TRIRCD_CONFDIR}/ircd.motd.sample
	@${MKDIR} ${TRIRCD_RUNDIR}
.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${WRKSRC}/doc/man/ircd.8 ${MANPREFIX}/man/man8/tr-ircd.8
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}/${FILE}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
