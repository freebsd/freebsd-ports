# $FreeBSD$

PORTNAME=	inih
DISTVERSIONPREFIX=	r
DISTVERSION=	53
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple .INI file parser written in C

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

TEST_DEPENDS=	bash:shells/bash

USES=		meson
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	benhoyt

do-test:
	@cd ${WRKSRC}/tests && \
		${REINPLACE_CMD} -e 's|gcc|${CC}|' unittest.sh && \
		./unittest.sh

.include <bsd.port.mk>
