# Created by: Marc van Woerkom <3d@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quake3
DISTVERSION=	1.11-6
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-demo
DISTNAME=	linuxq3ademo-${DISTVERSION}.x86
EXTRACT_SUFX=	.gz.sh

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake III Arena Demo

RESTRICTED=	Restrictive license by Loki Software
NO_CDROM=	${RESTRICTED}
NO_PACKAGE=	${RESTRICTED}

USE_LINUX=	yes
USE_LINUX_APPS+=dri
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

SUB_FILES=	q3demo

NO_STAGE=	yes
do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR} && ${TAIL} +165 ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} | \
		${TAR} zxf -

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/q3demo ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/x86/glibc-2.0/q3demo ${DATADIR}
	@${CP} -R ${WRKSRC}/demoq3 ${DATADIR}
	@${LN} -s ${LINUXBASE}/usr/X11R6/lib/libGL.so.1 ${DATADIR}/libGL.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${CP} -R ${WRKSRC}/Help/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
