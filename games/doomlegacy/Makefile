PORTNAME=	doomlegacy
PORTVERSION=	1.48.14
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${DISTVERSION:S,_,%20,}/
DISTNAME=	${PORTNAME}_${DISTVERSION}_source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}_${DISTVERSION}_common.zip

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Improved and extended version of Doom
WWW=		https://doomlegacy.sourceforge.net/

LICENSE=	GPLv2

USES=		gl gmake sdl tar:bzip2
USE_GL=		gl glu
USE_SDL=	mixer sdl
MAKE_ARGS=	OS=${OPSYS:tu}
MAKE_ENV=	CC_ENVIRONMENT=1 HAVE_ZLIB=1

PLIST_FILES=	bin/${PORTNAME} share/doom/dogs.wad share/doom/legacy.wad
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS LIBZIP
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT=	LIBZIP
ASM_BROKEN=	segmentation fault in ASM_PatchRowBytes()

ASM_BUILD_DEPENDS=	nasm:devel/nasm
ASM_MAKE_ENV=		USEASM=1

LIBZIP_DESC=		Zipped WAD file support via libzip
LIBZIP_LIB_DEPENDS=	libzip.so:archivers/libzip
LIBZIP_MAKE_ENV=	HAVE_LIBZIP=1

post-patch: .SILENT
# Adjust default WAD search path and disable IPX
	${REINPLACE_CMD} -e '/DEFWADS04/s|/.*|${DMDIR}"|' \
		-e '/USE_IPX/s|define|undef|' ${WRKSRC}/src/doomdef.h

pre-build:
	@${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} depend \
		-C ${BUILD_WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/doomlegacy ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DMDIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${PORTVERSION}_common/*.wad \
		${STAGEDIR}${DMDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/../doom-data/Makefile.include"
.include <bsd.port.mk>
