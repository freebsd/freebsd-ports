# $FreeBSD$

PORTNAME=	fatal
DISTVERSIONPREFIX=	v
DISTVERSION=	2021.03.08.00
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for fast software prototyping in modern C++

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	facebook

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PREFIX}/include
	${FIND} ${STAGEDIR}${PREFIX}/include -name "*.cpp" -delete
	${FIND} ${STAGEDIR}${PREFIX}/include -type d -empty -delete

.include <bsd.port.mk>
