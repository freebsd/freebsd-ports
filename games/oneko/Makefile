# New ports collection makefile for:	oneko
# Version required:	1.2
# Date created:		5 December 1994
# Whom:			asami
#
# $Id: Makefile,v 1.8 1996/12/30 21:33:31 max Exp $
#

DISTNAME=	oneko-1.2
CATEGORIES=	games
MASTER_SITES=	http://www.asahi-net.or.jp/~ZW6T-KND/oneko/

MAINTAINER=	candy@fct.kgc.co.jp

USE_IMAKE=	yes
MANCOMPRESSED=	yes
MAN6=		oneko.6

pre-configure:
	@echo "MANSUFFIX=6" >>${WRKSRC}/Imakefile

.include <bsd.port.mk>
