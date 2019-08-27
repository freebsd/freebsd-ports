# $FreeBSD$

PORTNAME=	skypat
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ unit and performance testing framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash

USES=		autoreconf compiler:c++11-lang gmake libtool
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	skymizer
GH_PROJECT=	SkyPat
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

post-install:
	@${MV} ${STAGEDIR}${DATADIR}/examples ${STAGEDIR}${EXAMPLESDIR}
	@${RM} -r ${STAGEDIR}${DATADIR}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libskypat.so.3.0.1

.include <bsd.port.mk>
