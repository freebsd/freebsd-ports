# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	atlast
PORTVERSION=	1.2
CATEGORIES=	lang
MASTER_SITES=	http://www.fourmilab.ch/atlast/download/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Autodesk Threaded Language Application System Toolkit

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/COPYING

ALL_TARGET=	${PORTNAME}
PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	atlast.html atlast.pdf

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "/^COPTIONS = /s, = .*, = ${CFLAGS}, " \
		-e "/^CC = /s,= .*, = ${CC}," \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
