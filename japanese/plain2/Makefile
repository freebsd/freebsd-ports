# New ports collection makefile for:	plain2
# Date created:		20 April 1997
# Whom:			nkazushi@highway.or.jp
#
# $FreeBSD$
#

PORTNAME=	plain2
PORTVERSION=	2.54
CATEGORIES=	japanese textproc
MASTER_SITES=	ftp://ftp.nec.co.jp/pub/packages/plain2/

MAINTAINER=	ports@freebsd.org

PORTCOMMENT=	A text converter from plain to any format

WRKSRC=		${WRKDIR}/${DISTNAME}/src
ALL_TARGET=	plain2

# Some hint for incorporating unofficial HTML support patch.
# Currently it is not supported.
#PATCH_SITES=	http://shika.aist-nara.ac.jp/products/DEST/plain2/
#PATCHFILES=	plain2-2.53-html.94aug14.patch.gz
#RUN_DEPENDS+=	tcsh:${PORTSDIR}/shells/tcsh
#PATCH_DIST_STRIP=	-p2 -F 3

.include <bsd.port.mk>
