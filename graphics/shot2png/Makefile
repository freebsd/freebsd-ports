# New ports collection makefile for:	shot2png
# Date created:				18 May 2001
# Whom:					nik
#
# $FreeBSD$
#

PORTNAME=	shot2png
PORTVERSION=	1.0
CATEGORIES=	graphics

MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=nik
NO_WRKSUBDIR=	yes

MAINTAINER=	nik@freebsd.org

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd

MAN1=		shot2png.1
MANCOMPRESSED=	yes

do-install:
	@cd ${WRKSRC}; ${MAKE} BINDIR=${LOCALBASE}/bin SHAREDIR=${LOCALBASE} install

.include <bsd.port.mk>
