# New ports collection makefile for:    ircd-rusnet
# Date created:                         20 Mar 2005
# Whom:                                 SeaD
#
# $FreeBSD$
#

# Patch for `--with-user' `--with-group' and `--with-netname'
# by Alex Lyashkov <umka at mail.sevinter.net>

# ircd.motd.sample taken from irc.tomsk.ru

PORTNAME=	ircd-rusnet
PORTVERSION=	1.4.2
CATEGORIES=	irc russian
MASTER_SITES=	http://gvs.rinet.ru/rusnet/
DISTNAME=	rusnet-${PORTVERSION}

MAINTAINER=	sead@mail.ru
COMMENT=	RusNet Internet Relay Chat Server

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

USER=		ircd
GROUP=		${USER}
NETWORK=	RusNet

VARDIR?=	${DESTDIR}/var
IRCD_CONFDIR?=	${PREFIX}/etc/ircd-rusnet
IRCD_CODEPAGES?=	${IRCD_CONFDIR}/codepages
IRCD_MOTD?=	${IRCD_CONFDIR}/ircd.motd
IRCD_LOGDIR?=	${VARDIR}/log/ircd
IRCD_RUNDIR?=	${VARDIR}/run/ircd

CONFIGURE_ARGS=	--sysconfdir=${IRCD_CONFDIR} --codepagedir=${IRCD_CODEPAGES} \
		--logdir=${IRCD_LOGDIR} --localstatedir=${IRCD_RUNDIR} \
		--with-user=${USER} --with-group=${GROUP} --with-netname=${NETWORK}

ALL_TARGET=	server tkserv client
BUILD_WRKSRC=	${WRKSRC}/build
INSTALL_TARGET=	install-server install-tkserv install-client
INSTALL_WRKSRC=	${WRKSRC}/build

CONFLICTS=	ircd-[0-9]*

MAN1=		irc.1
MAN5=		iauth.conf.5
MAN8=		ircd.8 iauth.8 ircdwatch.8

DOCS=		CHANGED FAQ doc/Authors doc/BUGS doc/ChangeLog doc/Etiquette \
		doc/INSTALL.appendix doc/INSTALL.txt doc/LICENSE doc/README \
		doc/RELEASE_NOTES doc/SERVICE.txt doc/alt-irc-faq \
		doc/iauth-internals.txt
LOGS=		ircd.log iauth.log tkserv.log

.if defined(WITHOUT_ZLIB)
CONFIGURE_ARGS+=--without-zlib
.else
CONFIGURE_ARGS+=--with-zlib
.endif

# seems to be broken
# .if defined(ENABLE_IPV6)
# CONFIGURE_ARGS+=--enable-ip6
# .endif

.if defined(ENABLE_DSM)
CONFIGURE_ARGS+=--enable-dsm
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"Does not build on amd64"
.endif

pre-configure:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-CONFIGURE

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/ircd.sh.sample ${PREFIX}/etc/rc.d
	${CP} ${FILESDIR}/ircd.motd.sample ${IRCD_CONFDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docfile in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif
.for logfile in ${LOGS}
	${TOUCH} ${IRCD_LOGDIR}/${logfile}
.endfor
	@${CHOWN} -R ${USER}:${GROUP} ${IRCD_LOGDIR}
	@${CHOWN} -R ${USER}:${GROUP} ${IRCD_RUNDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
