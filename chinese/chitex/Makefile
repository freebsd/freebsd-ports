# New ports collection makefile for:	zh-chitex
# Date created:		17 April 2001
# Whom:			Shen Chuan-Hsing (statue@freebsd.sinica.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	chitex
PORTVERSION=	6.1.2p7.8
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	ftp://dongpo.math.ncu.edu.tw/tex-archive/local/chitex/chitex/unix/%SUBDIR%/ \
		ftp://freebsd.sinica.edu.tw/pub/statue/chitex/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTFILES=	chitex6121.tar.gz chitex6122.tar.gz moe_kai.ttf.gz \
		moekai1.tgz moekai2.tgz moekai3.tgz moekatfm.tgz \
		nbsmi00lp.ttf.gz ngkai00mp.ttf.gz nuwgsung.tgz nuwpstfm.tgz \
		nuwpstj.ttf.gz nwdgkai.tgz nwdsung1.tgz nwdsung2.tgz \
		nwdsung3.tgz

MAINTAINER=	statue@freebsd.sinica.edu.tw

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX

DIST_SUBDIR=	chitex
WRKSRC=		${WRKDIR}/chitex612
NO_BUILD=	YES
NO_CDROM=	'Do not sell for profit.'

MAN1=		awka.1

do-extract:
	@${MKDIR} ${WRKDIR}
	@(cd ${WRKDIR} && \
	  ${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/chitex6121.tar.gz && \
	  ${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/chitex6122.tar.gz )

do-install:
	@(cd ${WRKSRC} && \
	  /usr/bin/env DISTDIR=${DISTDIR} $(SH) chsetupbig5Linux )

.include <bsd.port.mk>
