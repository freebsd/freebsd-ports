# Created by: andrew morton
# $FreeBSD$

PORTNAME=	cxxtest
PORTVERSION=	4.4
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	hselasky@freebsd.org
COMMENT=	Simple and powerful JUnit/CppUnit/xUnit-like framework for C++

LICENSE=	LGPL3+

USES=		gmake python:3.6+,run shebangfix

USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/python

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/cxxtest
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/cxxtest/* \
		${STAGEDIR}${PREFIX}/include/cxxtest/

.include <bsd.port.mk>
