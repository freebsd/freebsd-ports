# New ports collection makefile for:	ndtpd
# Date created:			4 Aug 1998
# Whom:				Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

PORTNAME=	ndtpd
PORTVERSION=	2.3.8
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/net/ndtp/ndtpd/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}+2.diff

MAINTAINER=	takamune@avrl.mei.co.jp

LIB_DEPENDS=	eb.3:${PORTSDIR}/japanese/eb

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${RUNDIR} --with-logdir=${LOGDIR} \
		--with-eb --with-eb-includes=${PREFIX}/include \
		--with-zlib --with-eb-libraries=${PREFIX}/lib

.if !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	Maybe_interactive_at_install_stage
.endif

# Local variables
LOGDIR=		/var/log
RUNDIR=		/var/run
STARTUP_SCRIPT=	ndtpd.sh.sample

post-extract:
	cd ${WRKSRC} && ${RM} -rf eb

post-build:
	${SED} "s,@prefix@,${PREFIX},; s,@rundir@,${RUNDIR},"\
	  ${FILESDIR}/${STARTUP_SCRIPT} > ${WRKDIR}/${STARTUP_SCRIPT}

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${STARTUP_SCRIPT} ${PREFIX}/etc/rc.d
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
