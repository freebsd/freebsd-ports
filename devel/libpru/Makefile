# $FreeBSD$

PORTNAME=	libpru
PORTVERSION=	0.4
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/rpaulo/libpru/get/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to interface with PRUs

LICENSE=	BSD2CLAUSE

IGNORE_DragonFly=	only supported on FreeBSD
BROKEN_mips=	Does not build: unrecognized command line option -Weverything
BROKEN_mips64=	Does not build: unrecognized command line option -Weverything
BROKEN_powerpc64=	Does not build: unrecognized command line option -Weverything
BROKEN_sparc64=	Does not build: unrecognized command line option -Weverything

USES=		cmake

WRKSRC=		${WRKDIR}/rpaulo-libpru-5a74157b82b8

.include <bsd.port.mk>
