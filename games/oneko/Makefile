# New ports collection makefile for:	oneko
# Date created:		5 December 1994
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	oneko
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cin.nihon-u.ac.jp/pub/Linux/PJE/PJE-0.1.5/sources/xclt/oneko/ \
		http://hp.vector.co.jp/authors/VA004959/oneko/

MAINTAINER=	candy@kgc.co.jp

USE_IMAKE=	yes
MAN6=		oneko.6

pre-configure:
	@${ECHO} "MANSUFFIX=6" >>${WRKSRC}/Imakefile

.include <bsd.port.mk>
