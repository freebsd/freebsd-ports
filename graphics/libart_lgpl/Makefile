# Created by: Hye-Shik Chang <perky@python.or.kr>
# $FreeBSD$

PORTNAME=	libart_lgpl
PORTVERSION=	2.3.21
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	GNOME
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for high-performance 2D graphics

USE_LDCONFIG=	yes
USES=		libtool:oldver pathfix tar:bzip2
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

CONFLICTS=	libart-[0-9]*

.include <bsd.port.mk>
