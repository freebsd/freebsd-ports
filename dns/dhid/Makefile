# New ports collection makefile for:	dhid
# Date created:		Sat Aug 21 06:13:59 EDT 1999
# Whom:			Oryx Gazella <oryx@ungulate.net>
#
# $FreeBSD$
#

PORTNAME=		dhid
PORTVERSION=		5.2
CATEGORIES=		dns
MASTER_SITES=		ftp://ftp.dhis.org/pub/dhis/

MAINTAINER=		oryx@ungulate.net
COMMENT=	DHIS client for updating dynamic DNS entries in dhisd DNS tables

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

LDFLAGS+=	-L${PREFIX}/lib
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

DOCFILES=	AUTHORS CONTRIBUTORS COPYRIGHT INSTALL README WHATSNEW
USE_REINPLACE=	yes

DHID_USER=	dhis
DHID_GROUP=	dhis
DHID_PID_DIR=	/var/run/dhis

post-patch:
	@${ECHO} "===>   Patching dhid.h and Makefile"
	@${REINPLACE_CMD} -e "s^__PREFIX__^${PREFIX}^g" ${WRKSRC}/dhid.h ${WRKSRC}/Makefile

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${ECHO_MSG} "===>   Installing ${PREFIX}/sbin/dhid."
	${INSTALL_PROGRAM} ${WRKSRC}/dhid ${PREFIX}/sbin
	@${ECHO_CMD} "sbin/dhid" >> ${TMPPLIST}
	@${ECHO_MSG} "===>   Installing ${PREFIX}/bin/genkeys."
	${INSTALL_PROGRAM} ${WRKSRC}/genkeys ${PREFIX}/bin
	@${ECHO_CMD} "bin/genkeys" >> ${TMPPLIST}
	@${ECHO_MSG} "===>   Installing ${PREFIX}/etc/dhid.conf.sample."
	${INSTALL_DATA} ${WRKSRC}/dhid.conf.sample ${PREFIX}/etc/dhid.conf.sample
	${CHOWN} ${DHID_USER}:${DHID_GROUP} ${PREFIX}/etc/dhid.conf.sample
	${CHMOD} 0600 ${PREFIX}/etc/dhid.conf.sample
	@${ECHO_CMD} "etc/dhid.conf.sample" >> ${TMPPLIST}
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
	@${ECHO_CMD} "etc/rc.d/dhid.sh.sample" >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation in ${DOCSDIR}"
	${MKDIR} ${DOCSDIR}
	${CHMOD} 755 ${DOCSDIR}
.for DOCFILE in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${DOCFILE} ${DOCSDIR}
	@${ECHO_CMD} "share/doc/${PORTNAME}/${DOCFILE}" >> ${TMPPLIST}
.endfor
	@${ECHO_CMD} "@dirrm share/doc/${PORTNAME}" >> ${TMPPLIST}
.endif
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
