# $FreeBSD$

PORTNAME=	cligen
DISTVERSION=	3.7.0-b.2080412
CATEGORIES=	devel

MAINTAINER=	dcornejo@netgate.com
COMMENT=	CLIgen is a Command-Line Interface generator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		bison gmake

USE_GITHUB=	yes
GH_ACCOUNT=	olofhagsand
GH_TAGNAME=	6da03b06cb5330f3ca9c619779565dceef4f203d

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so.3.7

.include <bsd.port.mk>
