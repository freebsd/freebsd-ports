# New ports collection makefile for:	ventrilo-server
# Date created:				29 March 2006
# Whom:					Anish Mistry
#
# $FreeBSD$
#

PORTNAME=	ventrilo
PORTVERSION=	3.0.3
CATEGORIES=	audio net
MASTER_SITES=	# http://www.ventrilo.com/download.php
PKGNAMESUFFIX=	-server
DISTNAME=	ventrilo_srv-${PORTVERSION}-FreeBSD-i386

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server side of the Ventrilo group voice chat system

LIB_DEPENDS=	stdc\\+\\+.3:${PORTSDIR}/misc/compat4x \
		m.2:${PORTSDIR}/misc/compat4x \
		c.4:${PORTSDIR}/misc/compat4x

.include <bsd.port.pre.mk>

IA32_BINARY_PORT=	yes
NO_BUILD=	yes
RESTRICTED=	Redistribution of pre-compiled binaries is not permitted
INSTALL_DIR=	${PREFIX}/ventrilo-server
USE_RC_SUBR=	${PORTNAME}${PKGNAMESUFFIX}
VENT_USER=	${PORTNAME}
USERS=		${VENT_USER}
GROUPS=		${USERS}
WRKSRC=	${WRKDIR}/ventsrv
SUB_FILES=	pkg-message

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE=	distfile can only be fetched if you accept the license. Go to http://www.ventrilo.com/dlprod.php?id=105 and put ${DISTFILES} into ${DISTDIR}
.endif

do-install:
	@${MKDIR} ${INSTALL_DIR}
	@${CHOWN} ${VENT_USER} ${INSTALL_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/ventrilo_srv ${INSTALL_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/ventrilo_status ${INSTALL_DIR}
	${INSTALL_DATA} ${WRKSRC}/ventrilo_srv.htm ${INSTALL_DIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${INSTALL_DIR}
	${INSTALL_DATA} ${WRKSRC}/ventrilo_srv.ini ${PREFIX}/etc/ventrilo_srv.ini.sample
	@if [ ! -f ${PREFIX}/etc/ventrilo_srv.ini ]; then \
		${CP} -p ${PREFIX}/etc/ventrilo_srv.ini.sample ${PREFIX}/etc/ventrilo_srv.ini ; \
		${CHMOD} 0640 ${PREFIX}/etc/ventrilo_srv.ini ; \
		${CHGRP} ${VENT_USER} ${PREFIX}/etc/ventrilo_srv.ini ; \
	fi
	${LN} -s ${PREFIX}/etc/ventrilo_srv.ini ${INSTALL_DIR}/ventrilo_srv.ini

post-install:
	@${CAT} ${PKGMESSAGE}

PKGDEINSTALL=	${PKGINSTALL}

.include <bsd.port.post.mk>
