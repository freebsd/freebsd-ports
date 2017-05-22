# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dunelegacy
PORTVERSION=	0.96.3
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Open source clone of Dune II

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	fails to compile: functional.h: 'std::bind' has not been declared

USES=		autoreconf compiler:c++11-lib tar:bzip2
GNU_CONFIGURE=	yes
USE_SDL=	sdl mixer
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
