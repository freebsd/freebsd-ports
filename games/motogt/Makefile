PORTNAME=	motogt
PORTVERSION=	20110505
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF/motogt/MotoGT1/
DISTNAME=	MotoGT-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D top-viewed motorcycle racing game
WWW=		https://motogt.sourceforge.net/

DEPRECATED=	Depends on obsolete devel/sfml1
EXPIRATION_DATE=2025-09-10

LICENSE=	GPLv2 CC-BY-SA-3.0
LICENSE_COMB=	multi
LICENSE_FILE_CC-BY-SA-3.0=	${WRKSRC}/doc/cc-by-sa.txt
LICENSE_FILE_GPLv2=	${WRKSRC}/doc/gpl.txt

LIB_DEPENDS=	libsfml1-system.so:devel/sfml1 \
		libpng.so:graphics/png

USES=		gl localbase:ldflags zip
USE_CXXSTD=	c++14
USE_GL=		gl

MAKEFILE=	Makefile.lnx
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	motogt

BUILD_WRKSRC=	${WRKSRC}/src
WRKSRC=		${WRKDIR}/MotoGT

PLIST_FILES=	bin/${PORTNAME} libexec/MotoGT.bin
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e '/#include/ s|SFML|&1|' ${WRKSRC}/data/src/editor.cpp ${WRKSRC}/src/*.h
	@${REINPLACE_CMD} -e 's|-lsfml|&1|g' ${WRKSRC}/src/Makefile.lnx

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/MotoGT.bin ${STAGEDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKDIR}/motogt ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
