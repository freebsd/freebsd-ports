# $FreeBSD$

PORTNAME=	genie
PORTVERSION=	g2018111101
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	GENie Project generator tool

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	bkaradzic
GH_PROJECT=	GENie
GH_TAGNAME=	d054bb1

MAKE_ARGS=	-C build/gmake.freebsd config=release CC=${CC} CXX=${CXX}
MAKE_JOBS_UNSAFE=	yes
PLIST_FILES=	bin/${PORTNAME}

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bsd/genie ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
