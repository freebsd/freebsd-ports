# Created by: Anish Mistry
# $FreeBSD$

PORTNAME=	ventrilo
PORTVERSION=	3.0.3
CATEGORIES=	audio net
MASTER_SITES=	# http://www.ventrilo.com/download.php
PKGNAMESUFFIX=	-server
DISTNAME=	ventrilo_srv-${PORTVERSION}-FreeBSD-i386

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Server side of the Ventrilo group voice chat system

RUN_DEPENDS=	compat4x-i386>0:misc/compat4x

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

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	distfile can only be fetched if you accept the license. Go to http://www.ventrilo.com/dlprod.php?id=105 and put ${DISTFILES} into ${DISTDIR}
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${INSTALL_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/ventrilo_srv ${STAGEDIR}${INSTALL_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/ventrilo_status ${STAGEDIR}${INSTALL_DIR}
	${INSTALL_DATA} ${WRKSRC}/ventrilo_srv.htm ${STAGEDIR}${INSTALL_DIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${INSTALL_DIR}
	${INSTALL_DATA} ${WRKSRC}/ventrilo_srv.ini ${STAGEDIR}${PREFIX}/etc/ventrilo_srv.ini.sample
	${LN} -s ${PREFIX}/etc/ventrilo_srv.ini ${STAGEDIR}${INSTALL_DIR}/ventrilo_srv.ini

PKGDEINSTALL=	${PKGINSTALL}

.include <bsd.port.post.mk>
