# New ports collection makefile for:    plan
# Version required:     1.6.1
# Date created:         Sat Jan 31, 1998
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.1.1.1 1998/01/31 21:59:32 obrien Exp $
#

#BROKEN=		"need JIS libraries in print.c that I do not have"
BROKEN=		"doesn't build properly from version 1.7.1"

MAKE_ENV+=	JAPANESE=yes

.include	"${.CURDIR}/../../misc/plan/Makefile"

PKGNAME=	ja-${DISTNAME}

MAINTAINER=     obrien@FreeBSD.org

FILESDIR=	${.CURDIR}/../../misc/plan/files
PATCHDIR=	${.CURDIR}/../../misc/plan/patches
PKGDIR=		${.CURDIR}/../../misc/plan/pkg

pre-install:
	${ECHO}	"share/doc/plan/plan_calSJ.ps" > ${PKGDIR}/PLIST
	${CAT}	${.CURDIR}/../../misc/plan/pkg/PLIST \
		>> ${PKGDIR}/PLIST
	${CP} ${.CURDIR}/../../misc/plan/pkg/DESCR  \
		${.CURDIR}/../../misc/plan/pkg/COMMENT  \
		${PKGDIR}/PLIST
