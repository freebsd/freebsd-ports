# New ports collection makefile for:	xgammon
# Date created:		02 January 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xgammon
PORTVERSION=	0.98
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_REDHAT}
MASTER_SITE_SUBDIR=	linux/6.2/en/os/${MACHINE_ARCH}/SRPMS
EXTRACT_SUFX=	-15.src.rpm

PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A backgammon program for X11

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes
MAN6=		xgammon.6

PATCH_FILES=	${PORTNAME}-${PORTVERSION}-dirent.patch

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@rpm2cpio.pl ${_DISTDIR}${DISTFILES} | (cd ${WRKDIR}; ${CPIO} -i)
	@${TAR} -xzf ${WRKDIR}/${DISTNAME}.tar.gz -C ${WRKDIR}

pre-patch:
	@${ECHO_MSG} "===>  Applying distribution patches for ${PKGNAME}"
.for file in ${PATCH_FILES}
	@${PATCH} ${PATCH_DIST_ARGS} < ${WRKDIR}/${file}
.endfor

.include <bsd.port.mk>
