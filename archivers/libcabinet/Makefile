PORTNAME=	libcabinet
DISTVERSION=	0.31
CATEGORIES=	archivers
MASTER_SITES=	https://codeberg.org/BSDforge/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	portmaster@BSDForge.com
COMMENT=	Portable library and utility to use Microsoft cabinet files (.cab)
WWW=		https://codeberg.org/BSDforge/libcabinet

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		uidfix
USE_LDCONFIG=	yes
SRCFILE=	${WRKSRC}/listcab.cpp
PROGFILE=	${SRCFILE:S/.cpp$//}
MAKE_ENV=	SRCCONF=/dev/null \
		WITHOUT_PROFILE=yes
WRKSRC=		${WRKDIR}/${PORTNAME}

post-build:
	${CXX} ${CXXFLAGS} -o ${PROGFILE} ${SRCFILE} -L${WRKSRC} -lcabinet -lz

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/cabinet

post-install:
	${INSTALL_PROGRAM} ${PROGFILE} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
