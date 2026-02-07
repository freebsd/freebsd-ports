PORTNAME=	stb
DISTVERSION=	2.37-20241109 # version is in deprecated/stb.h
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Stb single-file public domain libraries for C/C++
WWW=		https://github.com/nothings/stb/

LICENSE=	MIT PD
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE
LICENSE_FILE_PD=	${WRKSRC}/LICENSE

USES=		cpe
CPE_VENDOR=	${PORTNAME}_project

USE_GITHUB=	yes
GH_ACCOUNT=	nothings
GH_TAGNAME=	5c20573

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC} && ${INSTALL_DATA} *.c *.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
