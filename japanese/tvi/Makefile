# New ports collection makefile for: tvi
# Date created:		3 Jan 1999
# Whom:			SUGIMURA Takashi <sugimura@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tvi
PORTVERSION=	0.9.3
CATEGORIES=	japanese
MASTER_SITES=	http://www.kt.rim.or.jp/~motomu/tvi/Arc/

MAINTAINER=	sugimura@jp.FreeBSD.org

RUN_DEPENDS=	wish4.2jp:${PORTSDIR}/japanese/tk42

NO_BUILD=	yes

MAKE_ARGS=	PREFIX="${PREFIX}" \
		TVILIBDIR="${PREFIX}/lib/${PORTNAME}"

post-install:
	${RM} ${PREFIX}/lib/${PORTNAME}/*.orig

.include <bsd.port.mk>
