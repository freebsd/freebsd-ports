# ex:ts=8
# Ports collection makefile for:  plan
# Date created:			  Sat Jan 31, 1998
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=       plan
PORTVERSION=    1.8.4
CATEGORIES=	japanese

MAINTAINER=	ports@FreeBSD.org

MAKE_ENV+=	JAPANESE=yes

MASTERDIR=	${.CURDIR}/../../deskutils/plan

PLIST=	${WRKDIR}/PLIST
EXTRA_PATCHES=  ${.CURDIR}/files/patch-*

post-build:
	${ECHO_CMD} share/doc/plan/plan_calEUC.ps > ${WRKDIR}/PLIST
	${CAT} ${MASTERDIR}/pkg-plist >> ${WRKDIR}/PLIST

post-install:
	@${MKDIR} ${PREFIX}/share/netplan.dir
	${CHMOD} 1777 ${PREFIX}/share/netplan.dir
	${INSTALL_DATA} ${.CURDIR}/files/plan_calEUC.ps ${PREFIX}/share/doc/plan

.include	"${MASTERDIR}/Makefile"
