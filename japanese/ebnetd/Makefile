# New ports collection makefile for:	ndtpd
# Date created:			4 Aug 1998
# Whom:				Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

PORTNAME=	ndtpd
PORTVERSION=	3.1.5
PORTREVISION=	1
CATEGORIES=	japanese ipv6
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/net/ndtp/ndtpd/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/net/ndtp/ndtpd/

PATCH_SITES=	${MASTER_SITES}
#PATCHFILES=	${DISTNAME}+.diff

MAINTAINER=	takamune2004@yahoo.co.jp
COMMENT=	Server for accessing CD-ROM books with NDTP

LIB_DEPENDS=	eb.7:${PORTSDIR}/japanese/eb

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--localstatedir=${RUNDIR} --with-logdir=${LOGDIR}

.if !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	Maybe_interactive_at_install_stage
.endif

# Local variables
LOGDIR=		/var/log
RUNDIR=		/var/run
STARTUP_SCRIPT=	${PORTNAME}.sh.sample

post-build:
	${SED} "s,@prefix@,${PREFIX},; s,@rundir@,${RUNDIR},"\
	  ${FILESDIR}/${STARTUP_SCRIPT} > ${WRKDIR}/${STARTUP_SCRIPT}

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${STARTUP_SCRIPT} ${PREFIX}/etc/rc.d
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
