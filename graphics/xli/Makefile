# New ports collection makefile for:	xli
# Date created:		24 November 1994
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	xli
PORTVERSION=	1.17.0
PORTREVISION=	1
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB} \
		http://pantransit.reptiles.org/prog/
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	jkoshy@FreeBSD.org

LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_IMAKE=	yes
MAN1=		xli.1 xlito.1

post-patch:
	@${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/Imakefile

.include <bsd.port.mk>
