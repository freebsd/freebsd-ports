# New ports collection makefile for:	dhid
# Date created:		Sat Aug 21 06:13:59 EDT 1999
# Whom:			Oryx Gazella <oryx@ungulate.net>
#
# $FreeBSD$
#

PORTNAME=	dhid
PORTVERSION=	5.3
CATEGORIES=	dns
MASTER_SITES=	ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DHIS client for updating dynamic DNS entries in dhisd DNS tables

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

MAKE_ARGS+=	CC="${CC}" CFLAGS="${CFLAGS} -I${LOCALBASE}/include -DQRC=1" \
		LFLAGS="-L${LOCALBASE}/lib"

PORTDOCS=	AUTHORS CONTRIBUTORS COPYRIGHT INSTALL README WHATSNEW
PLIST_FILES=	sbin/dhid bin/genkeys etc/dhid.conf.sample etc/rc.d/dhid.sh.sample

DHID_USER=	dhis
DHID_GROUP=	dhis
DHID_PID_DIR=	/var/run/dhis

post-patch:
	@${ECHO} "===>   Patching dhid.h"
	@${REINPLACE_CMD} -e "s^__PREFIX__^${PREFIX}^g" ${WRKSRC}/dhid.h

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhid ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/genkeys ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/dhid.conf.sample ${PREFIX}/etc/dhid.conf.sample
	${CHOWN} ${DHID_USER}:${DHID_GROUP} ${PREFIX}/etc/dhid.conf.sample
	${CHMOD} 0600 ${PREFIX}/etc/dhid.conf.sample
	@${ECHO_CMD} "@exec ${CHOWN} ${DHID_USER}:${DHID_GROUP} %D/etc/dhid.conf.sample" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHMOD} 0600 %D/etc/dhid.conf.sample" >> ${TMPPLIST}
	${MKDIR} ${DHID_PID_DIR}
	${CHOWN} ${DHID_USER}:${DHID_GROUP} ${DHID_PID_DIR}
	${CHMOD} 0700 ${DHID_PID_DIR}
	@${ECHO_CMD} "@exec ${MKDIR} ${DHID_PID_DIR}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHOWN} ${DHID_USER}:${DHID_GROUP} ${DHID_PID_DIR}" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${CHMOD} 0700 ${DHID_PID_DIR}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RM} -rf /${DHID_PID_DIR}" >> ${TMPPLIST}
.if !exists(${PREFIX}/etc/rc.d/dhid.sh)
	@${ECHO_MSG} "===>   Installing ${PREFIX}/etc/rc.d/dhid.sh.sample startup file."
	${INSTALL_SCRIPT} -m 751 ${FILESDIR}/dhid.sh ${PREFIX}/etc/rc.d/dhid.sh.sample
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
