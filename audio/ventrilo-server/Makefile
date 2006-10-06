# New ports collection makefile for:	ventrilo-server
# Date created:				29 March 2006
# Whom:					Anish Mistry
#
# $FreeBSD$
#

PORTNAME=	ventrilo
PORTVERSION=	2.3.1
CATEGORIES=	audio net
MASTER_SITES=	# http://www.ventrilo.com/download.php
PKGNAMESUFFIX=	-server
DISTNAME=	ventrilo_srv-${PORTVERSION}-FreeBSD-i386

MAINTAINER=	amistry@am-productions.biz
COMMENT=	Server side of the Ventrilo group voice chat system

FETCH_DEPENDS=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget
LIB_DEPENDS=	c.4:${PORTSDIR}/misc/compat4x

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
RESTRICTED=	Redistribution of pre-compiled binaries is not permitted
NO_CDROM=	Redistribution of pre-compiled binaries is not permitted
INSTALL_DIR=	${PREFIX}/ventrilo-server
USE_RC_SUBR=	${PORTNAME}${PKGNAMESUFFIX}.sh
VENT_USER=	${PORTNAME}
FETCH_CMD=	${LOCALBASE}/bin/wget
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

do-fetch:
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
	${FETCH_CMD} --post-data "Download=Download" "http://download1.ventrilo.com/dl.php?server_freebsd_i386&2332415189" -O "${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}"
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@${TAR} -C ${WRKSRC} -zxf ${DISTDIR}/${DISTFILES}

do-install:
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL
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

post-deinstall:
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDEINSTALL} ${PORTNAME} POST-DEINSTALL

PKGDEINSTALL=	${PKGINSTALL}
.include <bsd.port.post.mk>
