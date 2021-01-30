# $FreeBSD$

PORTNAME=	objconv
DISTVERSION=	2.52
CATEGORIES=	devel
MASTER_SITES=	http://fuz.su/~fuz/objconv/

MAINTAINER=	fuz@fuz.su
COMMENT=	Agner Fog's object file converter

LICENSE=	GPLv1

NOT_FOR_ARCHS=		mips mips64 powerpc powerpc64 powerpcspe
NOT_FOR_ARCHS_REASON=	source/maindef.h:71:5: This machine has big-endian memory organization. Objconv program will not work

USES=		dos2unix zip
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
