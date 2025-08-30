PORTNAME=	objconv
DISTVERSION=	2.55_1
CATEGORIES=	devel
MASTER_SITES=	http://fuz.su/pub/objconv/ \
		https://www.agner.org/optimize/objconv.zip?dummy=/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Agner Fog's object file converter
WWW=		https://www.agner.org/optimize

LICENSE=	GPLv1

NOT_FOR_ARCHS=		mips mips64 powerpc powerpc64 powerpcspe
NOT_FOR_ARCHS_REASON=	source/maindef.h:71:5: This machine has big-endian memory organization. Objconv program will not work

USES=		dos2unix zip

# distfile hosted by maintainer and updated in tandem with port
# upstream distfile at https://agner.org/optimize not versioned
PORTSCOUT=	ignore:1
NO_WRKSUBDIR=	yes

post-extract:
	@${MKDIR} ${WRKSRC}/source ${WRKSRC}/extras
	@${TAR} xf ${WRKSRC}/source.zip -C ${WRKSRC}/source
	@${TAR} xf ${WRKSRC}/extras.zip -C ${WRKSRC}/extras

do-build:
	${CXX} ${CXXFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/source/*.cpp

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/extras ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/objconv-instructions.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/extras/*.asm ${STAGEDIR}${DATADIR}/extras

.include <bsd.port.mk>
