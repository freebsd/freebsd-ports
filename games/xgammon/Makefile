# New ports collection makefile for:	xgammon
# Version required:	0.98-12
# Date created:		02 January 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.10 1998/11/25 07:47:24 tg Exp $
#

DISTNAME=	xgammon-0.98
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.redhat.com/pub/redhat/current/SRPMS/SRPMS/ \
		ftp://ftp.mpi-sb.mpg.de:/pub/linux/mirror/ftp.redhat.com/redhat/redhat-5.2/SRPMS/SRPMS/
EXTRACT_SUFX=	-12.src.rpm

PATCH_DIST_STRIP=	-p1

MAINTAINER=	tg@FreeBSD.ORG

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/misc/rpm

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes
MAN6=		xgammon.6

PATCH_FILES=	${DISTNAME}-dirent.patch

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@rpm2cpio ${_DISTDIR}${DISTFILES} | (cd ${WRKDIR}; cpio -i)
	@tar -xzf ${WRKDIR}/${DISTNAME}.tar.gz -C ${WRKDIR}

pre-patch:
	@${ECHO_MSG} "===>  Applying distribution patches for ${PKGNAME}"
	@for file in ${PATCH_FILES}; do \
		${PATCH} ${PATCH_DIST_ARGS} < ${WRKDIR}/$$file; \
	done

.include <bsd.port.mk>
