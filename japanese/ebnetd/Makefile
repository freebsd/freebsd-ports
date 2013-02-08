# $FreeBSD$

PORTNAME=	ebnetd
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	japanese ipv6
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/eb/

MAINTAINER=	yasu@utahime.org
COMMENT=	Servers for accessing CD-ROM books via TCP/IP

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	eb:${PORTSDIR}/japanese/eb

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${RUNDIR} --with-logdir=${LOGDIR}

# Local variables
LOGDIR=		/var/log
RUNDIR=		/var/run
STARTUP_SCRIPT=	${PORTNAME}.sh

USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=	PREFIX=${PREFIX}

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
