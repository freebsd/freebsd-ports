# New ports collection makefile for:	txtmerge
# Date created:		20 Oct 1996
# Whom:			Yukihiro Nakai <nakai@mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	txtmerge
PORTVERSION=	1.01
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.freesoftware.com/pub/unixfreeware/graphics/ \
		ftp://ftp.math.bme.hu/pub/utils/xanim/ \
		ftp://ftp.kddlabs.co.jp/pub/graphics/gifanim/
DISTNAME=	txtmerge101
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	nakai@FreeBSD.org

WRKSRC=		${WRKDIR}/txtmerge
ALL_TARGET=	txtmerge

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/txtmerge ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/txtmerge
	${INSTALL_DATA} ${WRKSRC}/txtmerge.doc ${PREFIX}/share/doc/txtmerge

.include <bsd.port.mk>
