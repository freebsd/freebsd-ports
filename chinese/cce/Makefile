# Created by: Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
# $FreeBSD$

PORTNAME=	cce
PORTVERSION=	0.51
DISTVERSIONSUFFIX=	-02132004-dist
PORTREVISION=	2
CATEGORIES=	chinese
MASTER_SITES=	SF/${PORTNAME}2k/${PORTNAME}/Ver_${PORTVERSION}_02132004

PATCH_SITES=	http://www.chinatinco.com/freebsd/cce/ \
		http://www.525183.com/freebsd/cce/ \
		http://525183.serverbox.org/freebsd/cce/
PATCHFILES=	cce_0.51-1.diff.gz
PATCH_DIST_STRIP=-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console CJK Environment

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
LICENSE=	GPLv2

USES=		tar:tgz
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ONLY_FOR_ARCHS=	i386
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/man

.include <bsd.port.mk>
