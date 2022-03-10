PORTNAME=	stb
PORTVERSION=	g20211010
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Stb single-file public domain libraries for C/C++

LICENSE=	PD

USES=		cpe
CPE_VENDOR=	${PORTNAME}_project

USE_GITHUB=	yes
GH_ACCOUNT=	nothings
GH_TAGNAME=	af1a5bc

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC} && ${INSTALL_DATA} *.c *.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
