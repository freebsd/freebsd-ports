# New ports collection makefile for:    plan
# Version required:     1.6.1
# Date created:         Sat Jan 31, 1998
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.2 1998/04/17 18:08:35 obrien Exp $
#

#BROKEN=		"need JIS libraries in print.c that I do not have"
BROKEN=		"doesn't build properly from version 1.7.1"

MAKE_ENV+=	JAPANESE=yes

.include	"${.CURDIR}/../../deskutils/plan/Makefile"

PKGNAME=	ja-${DISTNAME}

MAINTAINER=     obrien@FreeBSD.org

FILESDIR=	${.CURDIR}/../../deskutils/plan/files
PATCHDIR=	${.CURDIR}/../../deskutils/plan/patches
PKGDIR=		${.CURDIR}/../../deskutils/plan/pkg

pre-install:
	${ECHO}	"share/doc/plan/plan_calSJ.ps" > ${PKGDIR}/PLIST
	${CAT}	${.CURDIR}/../../deskutils/plan/pkg/PLIST \
		>> ${PKGDIR}/PLIST
	${CP} ${.CURDIR}/../../deskutils/plan/pkg/DESCR  \
		${.CURDIR}/../../deskutils/plan/pkg/COMMENT  \
		${PKGDIR}/PLIST
