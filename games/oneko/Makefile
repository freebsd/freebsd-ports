# New ports collection makefile for:	oneko
# Version required:	1.2
# Date created:		5 December 1994
# Whom:			asami
#
# $Id: Makefile,v 1.11 1998/10/04 18:11:54 jseger Exp $
#

DISTNAME=	oneko-1.2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cin.nihon-u.ac.jp/pub/Linux/PJE/PJE-0.1.2/sources/xclt/ \
		http://hp.vector.co.jp/authors/VA004959/oneko/

MAINTAINER=	candy@kgc.co.jp

USE_IMAKE=	yes
MAN6=		oneko.6

pre-configure:
	@echo "MANSUFFIX=6" >>${WRKSRC}/Imakefile

.include <bsd.port.mk>
