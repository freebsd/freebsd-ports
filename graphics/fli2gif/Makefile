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
MASTER_SITES=	http://www.bovine.net/~jlawson/coding/fli2gif/
DISTNAME=	${PORTNAME}b

MAINTAINER=	ports@FreeBSD.org

NO_WRKSUBDIR=	yes

USE_ZIP=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500035
BROKEN=		"Does not compile on 5.0"
.endif

post-extract:
	@cd ${WRKSRC} && unzip -q -aa source.zip \
		&& ${LN} -sf GIF.CPP gif.cpp \
		&& ${LN} -sf FLIPLAY.CPP fliplay.cpp

do-build:
	@cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} *.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fli2gif ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/*.TXT ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
