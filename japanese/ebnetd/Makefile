# New ports collection makefile for:	ndtpd
# Version required:		2.3.5
# Date created:			4 Aug 1998
# Whom:				Motoyuki Kasahara <m-kasahr@sra.co.jp>
#
# $FreeBSD$
#

DISTNAME=	ndtpd-2.3.5
PKGNAME=	ja-ndtpd-2.3.5
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/net/ndtp/ndtpd/

MAINTAINER=	takamune@avrl.mei.co.jp

LIB_DEPENDS=	eb.3:${PORTSDIR}/japanese/eb

USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${VARDIR} --with-eb --with-zlib \
		--with-eb-includes=${PREFIX}/include \
		--with-eb-libraries=${PREFIX}/lib
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}"

.if !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	Maybe_interactive_at_install_stage
.endif
PLIST_SUB=	VARDIR=${VARDIR} OWNER=${OWNER} GROUP=${GROUP} MODE=${MODE}

# Local variables
VARDIR=		/var
OWNER=		nobody
GROUP=		nogroup
MODE=		755
STARTUP_SCRIPT=	ndtpd.sh.sample
INSTALL_DIR=	${INSTALL} -d -o ${OWNER} -g ${GROUP} -m ${MODE}

post-install:
	${SED} "s,@prefix@,${PREFIX}," ${FILESDIR}/${STARTUP_SCRIPT} \
	  > ${WRKDIR}/${STARTUP_SCRIPT}
	${INSTALL_SCRIPT} ${WRKDIR}/${STARTUP_SCRIPT} ${PREFIX}/etc/rc.d
	${INSTALL_DIR} ${VARDIR}/ndtpd
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
