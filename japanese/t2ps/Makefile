# New ports collection makefile for:	t2ps
# Date created:		17 June 2002
# Whom:			Yabu Tetsuro <yabu@uopmu.ees.osakafu-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	t2ps
PORTVERSION=	1.6d
CATEGORIES=	japanese print
MASTER_SITES=	http://www.uopmu.ees.osakafu-u.ac.jp/~yabu/soft/original/
DISTNAME=	t2ps

MAINTAINER=	yabu@uopmu.ees.osakafu-u.ac.jp

RUN_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

WRKSRC=		${WRKDIR}/t2ps-dir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/t2ps ${PREFIX}/bin

.include<bsd.port.mk>
