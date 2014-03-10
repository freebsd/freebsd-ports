# Created by: giffunip@asme.org
# $FreeBSD$

PORTNAME=	fli2gif
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://jeff.bovine.net/download/fli2gif/
DISTNAME=	${PORTNAME}b

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Automatic Flic to animated GIF converter

NO_WRKSUBDIR=	yes

USES=		dos2unix zip:infozip
DOS2UNIX_FILES=	fli2gif.cpp FLI2GIF.TXT

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	fli2gif.txt

post-extract:
	@cd ${WRKSRC} && ${UNZIP_CMD} -q source.zip \
		&& ${LN} -sf GIF.CPP gif.cpp \
		&& ${LN} -sf FLIPLAY.CPP fliplay.cpp

do-build:
	@cd ${WRKSRC} && ${CXX} ${CXXFLAGS} -o ${PORTNAME} *.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fli2gif ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/FLI2GIF.TXT ${STAGEDIR}${DOCSDIR}/fli2gif.txt

.include <bsd.port.mk>
