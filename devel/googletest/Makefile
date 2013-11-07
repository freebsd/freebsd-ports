# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	googletest
PORTVERSION=	1.5.0
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	gtest-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A framework for writing C++ tests on a variety of platforms

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PYTHON_BUILD=	yes

regression-test:
	cd ${WRKSRC}; ${MAKE} check

.include <bsd.port.mk>
