# New ports collection makefile for:	gridpix
# Version required:	2.1
# Date created:		19 July 1999
# Whom:			asami
#
# $FreeBSD$
#

DISTNAME=	GridPix-2.1
PKGNAME=	gridpix-2.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://stampede.cs.berkeley.edu/pub/GridPix/

MAINTAINER=	asami@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libpnm.a:${PORTSDIR}/graphics/netpbm
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

# create necessary directories -- don't want to depend on an http
# server port since we don't know which one the user wants
pre-install:
	${MKDIR} ${PREFIX}/www/cgi-bin ${PREFIX}/www/data/gridpix/docs

post-install:
	${MKDIR} ${PREFIX}/share/doc/gridpix
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/gridpix
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gridpix
	@${ECHO} "================================"
	@${CAT} ${PKGDIR}/MESSAGE
	@${ECHO} "================================"

.include <bsd.port.mk>
