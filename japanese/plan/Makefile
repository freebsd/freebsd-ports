# New ports collection makefile for:    plan
# Version required:     1.6.1
# Date created:         Sat Jan 31, 1998
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

#BROKEN=		"need JIS libraries in print.c that I do not have"
BROKEN=		"doesn't build properly from version 1.7.1"

MAKE_ENV+=	JAPANESE=yes

MASTERDIR=	${.CURDIR}/../../deskutils/plan

.include	"${MASTERDIR}/Makefile"

PKGNAME=	ja-${DISTNAME}

MAINTAINER=     obrien@FreeBSD.org

PLIST=		${WRKDIR}/PLIST

pre-install:
	${ECHO}	"share/doc/plan/plan_calSJ.ps" > ${PLIST}
	${CAT}	${PKGDIR}/PLIST >> ${PLIST}
