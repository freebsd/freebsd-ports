# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	motogt
PORTVERSION=	20110505
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF/motogt/
DISTNAME=	MotoGT-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	2D top-viewed motorcycle racing game

LIB_DEPENDS=	libsfml-system.so:${PORTSDIR}/devel/sfml \
		libpng.so:${PORTSDIR}/graphics/png

LICENSE=	GPLv2 CCbySA
LICENSE_COMB=	multi
LICENSE_NAME_CCbySA=	Creative Commons Attribution-ShareAlike
LICENSE_PERMS_CCbySA=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_FILE_CCbySA=	${WRKSRC}/doc/cc-by-sa.txt

USES=		zip
BUILD_WRKSRC=	${WRKSRC}/src
MAKEFILE=	Makefile.lnx
MAKE_JOBS_UNSAFE=	yes
CFLAGS+=	-I${LOCALBASE}/include/libpng15
MAKE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}"
SUB_FILES=	motogt
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

PLIST_FILES=	bin/${PORTNAME} libexec/MotoGT.bin
PORTDATA=	*

WRKSRC=		${WRKDIR}/MotoGT

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/MotoGT.bin ${STAGEDIR}${PREFIX}/libexec/
	${INSTALL_SCRIPT} ${WRKDIR}/motogt ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
