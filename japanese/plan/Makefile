# ex:ts=8
# Ports collection makefile for:  plan
# Date created:			  Sat Jan 31, 1998
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	plan
PORTVERSION=	1.9
CATEGORIES=	japanese

MAINTAINER=	shaun@inerd.com

MAKE_ENV+=	JAPANESE=yes

MASTERDIR=	${.CURDIR}/../../deskutils/plan

PLIST=	${WRKDIR}/PLIST
EXTRA_PATCHES=	${.CURDIR}/files/patch-*

post-build:
.if !defined(NOPORTDOCS)
	${ECHO_CMD} ${DOCSDIR:S|${PREFIX}/||}/plan_calEUC.ps > ${WRKDIR}/PLIST
.endif
	${CAT} ${MASTERDIR}/pkg-plist >> ${WRKDIR}/PLIST

post-install:
	@${MKDIR} ${DATADIR}/netplan.dir
	${CHMOD} 1777 ${DATADIR}/netplan.dir

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${.CURDIR}/files/plan_calEUC.ps ${DOCSDIR}
.endif

.include	"${MASTERDIR}/Makefile"
