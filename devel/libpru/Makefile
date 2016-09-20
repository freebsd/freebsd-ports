# $FreeBSD$

PORTNAME=	libpru
PORTVERSION=	0.4
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/rpaulo/libpru/get/

MAINTAINER=	rpaulo@FreeBSD.org
COMMENT=	Library to interface with PRUs

LICENSE=	BSD2CLAUSE

BROKEN_mips=	Does not build: unrecognized command line option -Weverything
BROKEN_mips64=	Does not build: unrecognized command line option -Weverything
BROKEN_powerpc64=	Does not build
BROKEN_sparc64=	Does not build: unrecognized command line option -Weverything

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=	only supported on FreeBSD
.endif

.if ${OSVERSION} < 1000510
IGNORE=	only supported on FreeBSD 10+
.endif

USES=		cmake

WRKSRC=		${WRKDIR}/rpaulo-libpru-5a74157b82b8

.include <bsd.port.mk>
