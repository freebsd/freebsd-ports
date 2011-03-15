# New ports collection makefile for:	gridpix
# Date created:		19 July 1999
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	gridpix
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pgollucci
DISTNAME=	GridPix-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Present large images efficiently over the Internet

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	${LOCALBASE}/lib/libnetpbm.a:${PORTSDIR}/graphics/netpbm
LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg

# create necessary directories -- don't want to depend on an http
# server port since we don't know which one the user wants
pre-install:
	${MKDIR} ${PREFIX}/www/cgi-bin ${PREFIX}/www/data/gridpix/docs

post-install:
	${MKDIR} ${PREFIX}/share/doc/gridpix
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/gridpix
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gridpix
	@${ECHO} "================================"
	@${CAT} ${PKGMESSAGE}
	@${ECHO} "================================"

.include <bsd.port.mk>
