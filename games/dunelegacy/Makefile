# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dunelegacy
PORTVERSION=	0.96.3
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Open source clone of Dune II

LICENSE=	GPLv2
LICENSE_FILES=	COPYING

USES=		tar:bzip2 compiler:c++11-lib
USE_AUTOTOOLS=	autoconf
USE_SDL=	sdl mixer
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000000
EXTRA_PATCHES=	files/extra-patch-include__misc__functional.h files/extra-patch-include__misc__memory.h
.endif

.include <bsd.port.post.mk>
