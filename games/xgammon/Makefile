# New ports collection makefile for:	xgammon
# Version required:	0.98-11
# Date created:		02 January 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.6 1998/09/28 02:18:41 steve Exp $
#

DISTNAME=	xgammon-0.98
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.redhat.com/pub/redhat/current/SRPMS/SRPMS/
EXTRACT_SUFX=	-11.src.rpm

PATCH_DIST_STRIP=	-p1

MAINTAINER=	tg@FreeBSD.ORG

BROKEN_ELF=	depends on rpm

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/misc/rpm

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes
MAN6=		xgammon.6

PATCH_FILES=	${DISTNAME}-dirent.patch

do-extract:
.if !defined(NO_WRKDIR)
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
.endif
	@rpm2cpio ${_DISTDIR}${DISTFILES} | (cd ${WRKDIR}; cpio -i)
	@tar -xzf ${WRKDIR}/${DISTNAME}.tar.gz -C ${WRKDIR}

pre-patch:
	@${ECHO_MSG} "===>  Applying distribution patches for ${PKGNAME}"
	@for file in ${PATCH_FILES}; do \
		${PATCH} ${PATCH_DIST_ARGS} < ${WRKDIR}/$$file; \
	done

.include <bsd.port.mk>
