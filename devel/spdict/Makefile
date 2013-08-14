# Created by: vanilla@
# $FreeBSD$

PORTNAME=	spdict
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A library of dictionary algorithms

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_LDCONFIG=	yes
USES=		gmake

MAKE_JOBS_UNSAFE=yes

do-install:
	@${MKDIR} ${PREFIX}/include/spdict
	@${INSTALL} ${WRKSRC}/*.hpp ${PREFIX}/include/spdict
	@${INSTALL} ${WRKSRC}/libspdict.so ${PREFIX}/lib/libspdict.so.1
	@${LN} -s ${PREFIX}/lib/libspdict.so.1 ${PREFIX}/lib/libspdict.so

.include <bsd.port.mk>
