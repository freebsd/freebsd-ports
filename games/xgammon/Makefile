# New ports collection makefile for:	xgammon
# Version required:	0.98-7
# Date created:		02 January 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id$
#

DISTNAME=	xgammon-0.98
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.redhat.com/pub/redhat/devel/srpms/SRPMS/
EXTRACT_SUFX=	-7.src.rpm

PATCH_DIST_STRIP=	-p1

MAINTAINER=	tg@FreeBSD.ORG

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes

PATCH_FILES=	${DISTNAME}-dirent.patch

do-extract:
.if !defined(NO_WRKDIR)
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
.endif
	@dd if=${_DISTDIR}${DISTFILES} bs=1706 skip=1 | gzip -cd | \
		(cd ${WRKDIR}; cpio -i)
	@tar -xzf ${WRKDIR}/${DISTNAME}.tar.gz -C ${WRKDIR}

pre-patch:
	@${ECHO_MSG} "===>  Applying distribution patches for ${PKGNAME}"
	@for file in ${PATCH_FILES}; do \
		${PATCH} ${PATCH_DIST_ARGS} < ${WRKDIR}/$$file; \
	done

.include <bsd.port.mk>
