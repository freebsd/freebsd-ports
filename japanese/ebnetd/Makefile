# New ports collection makefile for:	ebnetd
# Date created:			4 Aug 1998
# Whom:				Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

PORTNAME=	ebnetd
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	japanese ipv6
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/eb/

MAINTAINER=	yasu@utahime.org
COMMENT=	Servers for accessing CD-ROM books via TCP/IP

LIB_DEPENDS=	eb.14:${PORTSDIR}/japanese/eb

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${RUNDIR} --with-logdir=${LOGDIR}

# Local variables
LOGDIR=		/var/log
RUNDIR=		/var/run
STARTUP_SCRIPT=	${PORTNAME}.sh

USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

INFO=		ebnetd ebnetd-ja

post-build:
	${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/${STARTUP_SCRIPT} > ${WRKDIR}/${STARTUP_SCRIPT}

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${STARTUP_SCRIPT} ${PREFIX}/etc/rc.d
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
