# New ports collection makefile for:   cce
# Date created:                8 Oct 2003
# Whom:                        Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	cce
PORTVERSION=	0.51
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	SF/${PORTNAME}2k/${PORTNAME}/Ver_${PORTVERSION}_02132004
DISTNAME=	${PORTNAME}-${PORTVERSION}-02132004-dist
EXTRACT_SUFX=	.tgz
PATCH_SITES=	http://www.chinatinco.com/freebsd/cce/ \
		http://www.525183.com/freebsd/cce/ \
		http://525183.serverbox.org/freebsd/cce/
PATCHFILES=	cce_0.51-1.diff.gz
PATCH_DIST_STRIP=-p1

MAINTAINER=	sunrychen@gmail.com
COMMENT=	Console CJK Environment

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ONLY_FOR_ARCHS=	i386
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/man

MAN1=		cce.1 cceconv.1

.include <bsd.port.mk>
