# $FreeBSD$

PORTNAME=	lolcat
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0-9
DISTVERSIONSUFFIX=	-ga83e59d
CATEGORIES=	games

MAINTAINER=	gbe@FreeBSD.org
COMMENT=	High performance implementation of the famous lolcat

LICENSE=		WTFPL
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_CSTD=	c99

CONFLICTS_INSTALL=	rubygem-lolcat

USE_GITHUB=	yes
GH_ACCOUNT=	jaseg

PLIST_FILES=	bin/censor bin/lolcat

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/censor ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/lolcat ${STAGEDIR}${PREFIX}/bin
.include <bsd.port.mk>
