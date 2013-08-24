# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spdict
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Library of dictionary algorithms

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_LDCONFIG=	yes
USES=		gmake

do-install:
	@${MKDIR} ${PREFIX}/include/spdict
	${INSTALL_DATA} ${WRKSRC}/*.hpp ${PREFIX}/include/spdict
	${INSTALL_DATA} ${WRKSRC}/libspdict.so ${PREFIX}/lib/libspdict.so.1
	${LN} -s libspdict.so.1 ${PREFIX}/lib/libspdict.so

.include <bsd.port.mk>
