# New ports collection makefile for:	fli2gif
# Date created:		7 Jan 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	fli2gif
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://jeff.bovine.net/download/fli2gif/
DISTNAME=	${PORTNAME}b

MAINTAINER=	spam@rm-rf.kiev.ua
COMMENT=	Automatic Flic to animated GIF convertor

NO_WRKSUBDIR=	yes

USE_ZIP=	yes
USE_DOS2UNIX=	fli2gif.cpp FLI2GIF.TXT

post-extract:
	@cd ${WRKSRC} && ${UNZIP_CMD} -q source.zip \
		&& ${LN} -sf GIF.CPP gif.cpp \
		&& ${LN} -sf FLIPLAY.CPP fliplay.cpp

do-build:
	@cd ${WRKSRC} && ${CXX} ${CXXFLAGS} -o ${PORTNAME} *.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fli2gif ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/FLI2GIF.TXT ${DOCSDIR}
.endif

.include <bsd.port.mk>
